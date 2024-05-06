#include "newsgroup.h"
#include "article.h"

#include "../enums.h"

#include <algorithm>
#include <memory>
#include <tuple>

Newsgroup::Newsgroup(NewsgroupName n, NewsgroupID i) {
    this->name = n;
    this->id = i;
}

std::pair<ActionResult, std::vector<std::pair<ArticleID, ArticleName>>> Newsgroup::getArticles() {
    std::vector<std::pair<ArticleID, std::shared_ptr<Article>>> elements(this->articles.begin(), this->articles.end());

    // Sort the vector on the basis of key
    std::sort(elements.begin(), elements.end(), 
        [](const std::pair<ArticleID, std::shared_ptr<Article>>& a, const std::pair<ArticleID, std::shared_ptr<Article>>& b) {
            return a.first < b.first;
        }
    );

    std::vector<std::pair<ArticleID, ArticleName>> return_articles;
    for (const auto& pair : elements) {
        return_articles.push_back(std::make_pair(pair.first, pair.second->getTitle()));
    }
    return std::make_pair(ActionResult::ACCEPTED, return_articles);
}

ActionResult Newsgroup::newArticle(ArticleName title, Author author, Body body) {
    auto a_id = this->getNextID();
    this->articles.insert(std::make_pair(a_id, std::make_shared<Article>(Article(title, author, body, a_id))));
    return ActionResult::ACCEPTED;
}

std::pair<ActionResult, std::tuple<ArticleName, Author, Body>> Newsgroup::getArticle(const ArticleID& a_id) {
    auto article = this->articles.find(a_id);
    if (article != this->articles.end()) {
        return std::make_pair(ActionResult::ACCEPTED, std::make_tuple(article->second->getTitle(), article->second->getAuthor(), article->second->getBody()));
    } else {
        return std::make_pair(ActionResult::ART_DOES_NOT_EXIST, std::make_tuple("", "", ""));
    }
}

ActionResult Newsgroup::removeArticle(const ArticleID& a_id) {
    const bool ok = this->articles.erase(a_id) > 0;
    return ok ? ActionResult::ACCEPTED : ActionResult::ART_DOES_NOT_EXIST;
}

ArticleID Newsgroup::getNextID() {
    return ++nextID;
}

ArticleID Newsgroup::getID() const {
    return this->id;
}

ArticleName Newsgroup::getName() const {
    return this->name;
}
