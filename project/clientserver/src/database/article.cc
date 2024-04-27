#include <ostream>
#include <string>
#include "enums.h"
#include "article.h"

Article::Article(ArticleName title, Author author, Body body) {
    this->title = title;
    this->author = author;
    this->body = body;
    this->identification_number = ++article_counter;
}

void Article::printArticle(std::ostream out) {
    out << title << std::endl << author << std::endl << body << std::endl;
}