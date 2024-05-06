#include "diskDatabase.h"
#include "database/databaseExceptions.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std::filesystem;

DiskDatabase::DiskDatabase() {
    if (!exists(this->root)) {
        create_directory(this->root);
    }
    path id_path = this->root / "uniqueID.txt";
    if (!exists(id_path)) {
        writeNextNewsgroupID(1);
    }
}

std::pair<ActionResult, std::vector<std::pair<NewsgroupID, NewsgroupName>>> DiskDatabase::listNewsgroups() {
    std::vector<std::pair<NewsgroupID, NewsgroupName>> elements;

    for (const auto& entry : directory_iterator(this->root)) {
        if (entry.is_directory()) {
            path metadata_path = entry.path() / "metadata.txt";
            std::ifstream metadata_file(metadata_path);
            if (metadata_file.is_open()) {
                std::string line;
                std::getline(metadata_file, line);
                NewsgroupID id = std::stoi(line);   // Casting unsafe but w/e for now

                NewsgroupName name;
                std::getline(metadata_file, name);

                elements.push_back(std::make_pair(id, name));
            } else {
                std::cerr << "Failed to open " << metadata_path << '\n';
                throw DiskDatabaseException();
            }
        }
    }

    std::sort(elements.begin(), elements.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    return std::make_pair(ActionResult::ACCEPTED, elements);
}

ActionResult DiskDatabase::addNewsgroup(const NewsgroupName& name) {
    for (const auto& entry : directory_iterator(this->root)) {
        if (entry.is_directory()) {
            NewsgroupName current_name;
            path metadata_path = entry.path() / "metadata.txt";

            std::ifstream metadata_file(metadata_path);
            if (metadata_file.is_open()) {
                std::getline(metadata_file, current_name);
                std::getline(metadata_file, current_name);
            } else {
                std::cerr << "Failed to open " << metadata_path << '\n';
                throw DiskDatabaseException();
            }
            if (name == current_name) {
                return ActionResult::NG_ALREADY_EXISTS;
            }
        }
    }

    int id = this->getNextNewsgroupID();
    writeNextNewsgroupID(id + 1);

    // Create the directory for the newsgroup
    path newsgroup_path = this->root / std::to_string(id);
    create_directory(newsgroup_path);
    writeNextArticleID(newsgroup_path, 1);

    // Create the metadata.txt file
    std::ofstream metadata_file(newsgroup_path / "metadata.txt");
    metadata_file << id << "\n" << name;
    metadata_file.close();

    return ActionResult::ACCEPTED;
}

ActionResult DiskDatabase::removeNewsgroup(const NewsgroupID& ng_id) {
    path newsgroup_path = this->root / std::to_string(ng_id);
    if (exists(newsgroup_path)) {
        remove_all(newsgroup_path);
        return ActionResult::ACCEPTED;
    } else {
        return ActionResult::NG_DOES_NOT_EXIST;
    }
}
std::pair<ActionResult, std::vector<std::pair<ArticleID, ArticleName>>> DiskDatabase::getArticles(const NewsgroupID& ng_id) {
    std::vector<std::pair<ArticleID, ArticleName>> articles;
    path newsgroup_path = this->root / std::to_string(ng_id);
    
    if (exists(newsgroup_path)) {
        for (const auto& entry : directory_iterator(newsgroup_path)) {
            if (entry.is_directory()) {
                ArticleID article_id;
                ArticleName article_name;

                std::string metadata_path = entry.path() / "metadata.txt";
                std::ifstream article_metadata(metadata_path);
                if (article_metadata.is_open()) {
                    std::string line;
                    std::getline(article_metadata, line);
                    article_id = std::stoi(line);

                    std::getline(article_metadata, article_name);
                } else {
                    std::cerr << "Failed to open " << metadata_path << '\n';
                    throw DiskDatabaseException();
                }
                articles.push_back(std::make_pair(article_id, article_name));
            }
        }
        std::sort(articles.begin(), articles.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        return std::make_pair(ActionResult::ACCEPTED, articles);
    } else {
        return std::make_pair(ActionResult::NG_DOES_NOT_EXIST, articles);
    }
}
ActionResult DiskDatabase::newArticle(const NewsgroupID& ng_id, const ArticleName& name, const Author& author, const Body& body) {
    path newsgroup_path = this->root / std::to_string(ng_id);
    if (exists(newsgroup_path)) {
        // Generate a unique ID for the article
        int article_id = getNextArticleID(newsgroup_path);
        writeNextArticleID(newsgroup_path, article_id + 1);
        path article_path = newsgroup_path / std::to_string(article_id);

        // Create article directory
        create_directory(article_path);

        // Fill metadata.txt and body.txt
        std::string metadata_path = article_path / "metadata.txt";
        std::ofstream article_metadata(metadata_path);
        if (article_metadata.is_open()) {
            article_metadata << std::to_string(article_id) << std::endl << name << std::endl << author;
        } else {
            std::cerr << "Failed to open " << metadata_path << std::endl;
            throw DiskDatabaseException();
        }

        std::string body_path = article_path / "body.txt";
        std::ofstream article_body(body_path);
        if (article_body.is_open()) {
            article_body << body;
        } else {
            std::cerr << "Failed to open " << body_path << std::endl;
            throw DiskDatabaseException();
        }

        return ActionResult::ACCEPTED;
    } else {
        return ActionResult::NG_DOES_NOT_EXIST;
    }
}

ActionResult DiskDatabase::removeArticle(const NewsgroupID& ng_id, const ArticleID& art_id) {
    path newsgroup_path = this->root / std::to_string(ng_id);
    if (exists(newsgroup_path)) {
        path article_path = newsgroup_path / std::to_string(art_id);
        if (exists(article_path)) {
            std::filesystem::remove_all(article_path);
            return ActionResult::ACCEPTED;
        } else {
            return ActionResult::ART_DOES_NOT_EXIST;
        }
    } else {
        return ActionResult::NG_DOES_NOT_EXIST;
    }
}

std::pair<ActionResult, std::tuple<ArticleName, Author, Body>> DiskDatabase::getArticle(const NewsgroupID& ng_id, const ArticleID& art_id) {
    path newsgroup_path = this->root / std::to_string(ng_id);
    if (exists(newsgroup_path)) {
        path article_path = newsgroup_path / std::to_string(art_id);
        if (exists(article_path)) {
            ArticleName name;
            Author author;
            Body body;
            
            path metadata_path = article_path / "metadata.txt";
            std::ifstream metadata_file(metadata_path);
            if (metadata_file.is_open()) {
                std::getline(metadata_file, name);  // Skip ID
                std::getline(metadata_file, name);
                std::getline(metadata_file, author);
                metadata_file.close();
            } else {
                std::cerr << "Failed to open " << metadata_path << std::endl;
                throw DiskDatabaseException();
            }

            path body_path = article_path / "body.txt";
            std::ifstream body_file(body_path);
            if (body_file.is_open()) {
                std::string line;
                std::stringstream ss;
                while (std::getline(body_file,line)) {
                    ss << line;
                    if (!body_file.eof()) {
                        ss << std::endl;
                    }
                }
                body = ss.str();
                body_file.close();
            } else {
                std::cerr << "Failed to open " << body_path << std::endl;
                throw DiskDatabaseException();
            }

            return std::make_pair(ActionResult::ACCEPTED, std::make_tuple(name, author, body));
        } else {
            return std::make_pair(ActionResult::ART_DOES_NOT_EXIST, std::make_tuple("", "", ""));
        }
    } else {
        return std::make_pair(ActionResult::NG_DOES_NOT_EXIST, std::make_tuple("", "", ""));
    }
}

// Private helper functions
void DiskDatabase::writeNextNewsgroupID(int id) {
    path unique_id_path = this->root / "uniqueID.txt";
    std::ofstream metadata(unique_id_path, std::ios::trunc);     // Overwrites the file if exists (trunc)
    if (metadata.is_open()) {
        metadata << id;
        metadata.close();
    } else {
        std::cerr << "Can't write id to root id." << std::endl;
        throw DiskDatabaseException();
    }
}

NewsgroupID DiskDatabase::getNextNewsgroupID() {
    NewsgroupID id;
    path unique_id_path = this->root / "uniqueID.txt";
    std::ifstream metadata(unique_id_path);
    if (metadata.is_open()) {
        metadata >> id;
        metadata.close();
    } else {
        std::cerr << "Cant get ID from root id." << std::endl;
        throw DiskDatabaseException();
    }
    return id;
}

void DiskDatabase::writeNextArticleID(path newsgroup_path, int id) {
    path id_path = newsgroup_path / "uniqueID.txt";
    std::ofstream id_file(id_path, std::ios::trunc);
    if (id_file.is_open()) {
        id_file << id;
        id_file.close();
    } else {
        std::cerr << "Cant write ID to " << id_path << std::endl;
        throw DiskDatabaseException();
    }
}

ArticleID DiskDatabase::getNextArticleID(path newsgroup_path) {
    ArticleID id;
    path id_path = newsgroup_path / "uniqueID.txt";
    std::ifstream metadata(id_path);
    if (metadata.is_open()) {
        metadata >> id;
        metadata.close();
    } else {
        std::cerr << "Cant get ID from " << id_path;
        throw DiskDatabaseException();
    }
    return id;
}
