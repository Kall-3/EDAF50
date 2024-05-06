#include "primeDatabase.h"
#include "database/enums.h"
#include "newsgroup.h"

#include <algorithm>
#include <memory>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

/*PrimeDatabase::PrimeDatabase() {
    std::unordered_map<NewsgroupID, Newsgroup> empty = {};
    this->groups = std::make_shared<std::unordered_map<NewsgroupID, Newsgroup>>(empty);
}*/

std::pair<ActionResult, std::vector<std::pair<NewsgroupID, NewsgroupName>>> PrimeDatabase::listNewsgroups() {
    std::vector<std::pair<NewsgroupID, std::shared_ptr<Newsgroup>>> elements(this->groups.begin(), this->groups.end());

    // Sort the vector on the basis of key
    std::sort(elements.begin(), elements.end(), 
        [](const std::pair<NewsgroupID, std::shared_ptr<Newsgroup>>& a, const std::pair<NewsgroupID, std::shared_ptr<Newsgroup>>& b) {
            return a.first < b.first;
        }
    );

    std::vector<std::pair<NewsgroupID, NewsgroupName>> return_groups;
    for (const auto& pair : elements) {
        return_groups.push_back(std::make_pair(pair.second->getID(), pair.second->getName()));
    }
    return std::make_pair(ActionResult::ACCEPTED, return_groups);
}

ActionResult PrimeDatabase::addNewsgroup(const NewsgroupName& name) {
    // Check if name exists in database, no duplicates allowed
    auto found = std::find_if(this->groups.begin(), this->groups.end(),
        [&name](const std::pair<NewsgroupID, std::shared_ptr<Newsgroup>>& pair) {
            return (pair.second->getName() == name);
        });

    if (found != groups.end()) {
        return ActionResult::NG_ALREADY_EXISTS;
    } else {
        // Unique incrementing ID
        const int id = getNextID();
        groups.insert(std::make_pair(id, std::make_shared<Newsgroup>(Newsgroup(name, id))));
        return ActionResult::ACCEPTED;
    }
}

ActionResult PrimeDatabase::removeNewsgroup(const NewsgroupID& id) {
    const bool ok = groups.erase(id) > 0;
    return ok ? ActionResult::ACCEPTED : ActionResult::NG_DOES_NOT_EXIST;
}

std::pair<ActionResult, std::vector<std::pair<ArticleID, ArticleName>>> PrimeDatabase::getArticles(const NewsgroupID& id) {
    auto group = findNewsgroup(id);
    if (group != nullptr) {
        return group->getArticles();
    } else {
        // Return empty vector if no group found
        return std::make_pair(ActionResult::NG_DOES_NOT_EXIST, std::vector<std::pair<ArticleID, ArticleName>>());
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

std::pair<ActionResult, std::tuple<ArticleName, Author, Body>> PrimeDatabase::getArticle(const NewsgroupID& ng_id, const ArticleID& a_id) {
    auto group = findNewsgroup(ng_id);
    if (group != nullptr) {
        return group->getArticle(a_id);
    } else {
        return std::make_pair(ActionResult::NG_DOES_NOT_EXIST, std::make_tuple("", "", ""));
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

std::shared_ptr<Newsgroup> PrimeDatabase::findNewsgroup(const NewsgroupID& newsgroup_id) {
    auto it = groups.find(newsgroup_id);
    if (it != groups.end()) {
        return it->second;
    } else {
        return nullptr;
    }
}

NewsgroupID PrimeDatabase::getNextID() {
    return ++nextID;
}
