#include "newsgroup.h"
#include "database/enums.h"
#include <algorithm>

Newsgroup::Newsgroup(NewsgroupName name, NewsgroupID id) {
    this->name = name;
    this->id = id;
}

std::pair<ActionResult, std::vector<Article>> Newsgroup::getArticles() {
    std::vector<std::pair<ArticleID, Article>> elements(this->articles.begin(), this->articles.end());

    // Sort the vector on the basis of key
    std::sort(elements.begin(), elements.end(), 
        [](const std::pair<ArticleID, Article>& a, const std::pair<ArticleID, Article>& b) {
            return a.first < b.first;
        }
    );

    std::vector<Article> return_articles;
    for (const auto& pair : elements) {
        return_articles.push_back(pair.second);
    }
    return std::make_pair(ActionResult::ACCEPTED, return_articles);
}

ActionResult Newsgroup::newArticle(ArticleName title, Author author, Body body) {
    auto a_id = this->getNextID();
    this->articles.insert(std::make_pair(a_id, Article(title, author, body, a_id)));
    return ActionResult::ACCEPTED;
}

std::pair<ActionResult, Article> Newsgroup::getArticle(const ArticleID& a_id) {
    auto article = this->articles.find(a_id);
    if (article != this->articles.end()) {
        return std::make_pair(ActionResult::ACCEPTED, article->second);
    } else {
        return std::make_pair(ActionResult::ART_DOES_NOT_EXIST, Article("", "", "", -1));
    }

}

ActionResult Newsgroup::removeArticle(const ArticleID& a_id) {
    const bool ok = this->articles.erase(a_id) > 0;
    return ok ? ActionResult::ACCEPTED : ActionResult::ART_DOES_NOT_EXIST;
}

ArticleID Newsgroup::getNextID() {
    return ++nextID;
}

ArticleID Newsgroup::getID() {
    return this->id;
}

ArticleName Newsgroup::getName() {
    return this->name;
}
