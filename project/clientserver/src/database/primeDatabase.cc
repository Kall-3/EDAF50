#include "primeDatabase.h"
#include "database/database.h"
#include "database/enums.h"
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <utility>

std::pair<ActionResult, std::vector<Newsgroup>> PrimeDatabase::listNewsgroups() {
    auto result = std::vector<Newsgroup>();
    for (auto group : groups) {
        result.push_back(*group.second);
    }
    return std::make_pair(0, result);
}

ActionResult PrimeDatabase::addNewsgroup(const NewsgroupName& name) {
    const bool ok = groups.insert(std::make_pair(getNextID(), new Newsgroup(name))).second;
    if (!ok) {
        this->err << "Name " << name << " is taken." << std::endl;
    }
    return ok ? 0 : 1;
}

ActionResult PrimeDatabase::removeNewsgroup(const NewsgroupID& id) {
    size_t ok = groups.erase(id) > 0;
    if (!ok) {
        this->err << "No newsgroup to delete with id '" << id << "'." << std::endl;
    }
    return ok ? 0 : 1;;
}

std::pair<ActionResult, std::vector<Article>> PrimeDatabase::listArticles(const NewsgroupID& id) {
    auto group = findNewsgroup(id);
    if (group != nullptr) {
        return group->listArticles();
    } else {
        // Return empty vector if no group found, with error code 1
        return std::make_pair(1, std::vector<Article>());
    }
}

ActionResult PrimeDatabase::newArticle(const NewsgroupID& id, const ArticleName& title, const Author& author, const Body& body) {
    auto group = findNewsgroup(id);
    if (group != nullptr) {
        return group->newArticle(title, author, body);
    } else {
        // Error code for no newsgroup
        return 1;
    }
}

ActionResult PrimeDatabase::getArticle(const NewsgroupID& newsgroup_id, const ArticleID& article_id) {
    auto group = findNewsgroup(newsgroup_id);
    if (group != nullptr) {
        group->printArticle(article_id, this->out);
    }
}

ActionResult PrimeDatabase::removeArticle(const NewsgroupID& newsgroup_id, const ArticleID& article_id) {
    auto group = findNewsgroup(newsgroup_id);
    if (group != nullptr) {
        group->removeArticle(article_id);
    }
}

Newsgroup* PrimeDatabase::findNewsgroup(const NewsgroupID& newsgroup_id) {
    auto it = groups.find(newsgroup_id);
    if (it != groups.end()) {
        return it->second;
    } else {
        out << "No newsgroup found with ID " << newsgroup_id << std::endl;
        return nullptr;
    }
}
