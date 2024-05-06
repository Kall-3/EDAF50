#include "article.h"

Article::Article(ArticleName t, Author a, Body b, ArticleID i) {
    this->title = t;
    this->author = a;
    this->body = b;
    this->id = i;
}

ArticleID Article::getID() const {
    return this->id;
}

ArticleName Article::getTitle() const {
    return this->title;
}

Author Article::getAuthor() const {
    return this->author;
}

Body Article::getBody() const {
    return this->body;
}
