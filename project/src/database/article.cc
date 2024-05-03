#include "article.h"

Article::Article(ArticleName title, Author author, Body body, ArticleID id) {
    this->title = title;
    this->author = author;
    this->body = body;
    this->id = id;
}

ArticleID Article::getID() {
    return this->id;
}

ArticleName Article::getTitle() {
    return this->title;
}

Author Article::getAuthor() {
    return this->author;
}

Body Article::getBody() {
    return this->body;
}
