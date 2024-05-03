#ifndef ARTICLE_H
#define ARTICLE_H

#include "enums.h"

class Article {
public:
    /* New article */
    Article(ArticleName title, Author author, Body body, ArticleID id);

    /* Remove article */
    ~Article() = default;

    ArticleID getID();
    ArticleName getTitle();
    Author getAuthor();
    Body getBody();

private:
    /* Member variables */
    ArticleName title;
    Author author;
    Body body;
    ArticleID id;
};

#endif
