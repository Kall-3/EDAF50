#include "newsgroup.h"
#include "database/enums.h"

Newsgroup::Newsgroup(NewsgroupName name) {
    this->identification_number = ++newsgroup_counter;
    this->name = name;
}

std::pair<ActionResult, std::vector<Article>> Newsgroup::getArticles() {
    std::vector<Article> return_articles;
    for (auto article : this->articles) {
        return_articles.push_back(article.second);
    }
    return std::make_pair(0, return_articles);
}

ActionResult newArticle(ArticleName title, Author author, Body body) {
    return this->articles.insert(std::make_pair(Article.getNextID(), Article(title, author, body)));
}

std::pair<ActionResult, Article> getArticle(const ArticleID& id) {
    auto article = this->articles.find(id);
    if (article != this->articles.end()) {
        return std::make_pair(0, article->second);
    } else {
        return std::make_pair(1, Article("", "", ""));
    }

}

ActionResult removeArticle(ArticleID id) {
    return this->articles.erase(id) > 0 ? 0 : 1;
}
