#include "primeDatabase.h"
#include <iostream>
#include <algorithm>

std::pair<ActionResult, std::vector<Newsgroup>> PrimeDatabase::listNewsgroups() {
    std::vector<std::pair<NewsgroupID, Newsgroup*>> elements(this->groups.begin(), this->groups.end());

    // Sort the vector on the basis of key
    std::sort(elements.begin(), elements.end(), 
        [](const std::pair<NewsgroupID, Newsgroup*>& a, const std::pair<NewsgroupID, Newsgroup*>& b) {
            return a.first < b.first;
        }
    );

    std::vector<Newsgroup> return_groups;
    for (const auto& pair : elements) {
        return_groups.push_back(*pair.second);
    }
    return std::make_pair(ActionResult::ACCEPTED, return_groups);
}

ActionResult PrimeDatabase::addNewsgroup(const NewsgroupName& name) {
    // Check if name exists in database, no duplicates allowed
    auto found = std::find_if(this->groups.begin(), this->groups.end(),
        [&name](const std::pair<NewsgroupID, Newsgroup*>& pair) {
            return (pair.second->getName() == name);
        });

    if (found != groups.end()) {
        return ActionResult::NG_ALREADY_EXISTS;
    } else {
        // Unique incrementing ID
        const int id = getNextID();
        groups.insert(std::make_pair(id, new Newsgroup(name, id)));
        return ActionResult::ACCEPTED;
    }
}

ActionResult PrimeDatabase::removeNewsgroup(const NewsgroupID& id) {
    const bool ok = groups.erase(id) > 0;
    if (!ok) {
        this->err << "No newsgroup to delete with id '" << id << "'." << std::endl;
    }
    return ok ? ActionResult::ACCEPTED : ActionResult::NG_DOES_NOT_EXIST;
}

std::pair<ActionResult, std::vector<Article>> PrimeDatabase::getArticles(const NewsgroupID& id) {
    auto group = findNewsgroup(id);
    if (group != nullptr) {
        return group->getArticles();
    } else {
        // Return empty vector if no group found, with error code 1
        return std::make_pair(ActionResult::NG_DOES_NOT_EXIST, std::vector<Article>());
    }
}

ActionResult PrimeDatabase::newArticle(const NewsgroupID& id, const ArticleName& title, const Author& author, const Body& body) {
    auto group = findNewsgroup(id);
    if (group != nullptr) {
        return group->newArticle(title, author, body);
    } else {
        // Error code for no newsgroup
        return ActionResult::NG_DOES_NOT_EXIST;
    }
}

std::pair<ActionResult, Article> PrimeDatabase::getArticle(const NewsgroupID& ng_id, const ArticleID& a_id) {
    auto group = findNewsgroup(ng_id);
    if (group != nullptr) {
        return group->getArticle(a_id);
    } else {
        return std::make_pair(ActionResult::NG_DOES_NOT_EXIST, Article("", "", "", 1));
    }
}

ActionResult PrimeDatabase::removeArticle(const NewsgroupID& ng_id, const ArticleID& a_id) {
    auto group = findNewsgroup(ng_id);
    if (group != nullptr) {
        return group->removeArticle(a_id);
    } else {
        return ActionResult::NG_DOES_NOT_EXIST;
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

NewsgroupID PrimeDatabase::getNextID() {
    return ++nextID;
}
