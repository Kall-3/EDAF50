#ifndef ARTICLE_H
#define ARTICLE_H

#include "database/enums.h"

class Article {
public:
    /* New article */
    Article(ArticleName t, Author a, Body b, ArticleID i);

    /* Remove article */
    ~Article() = default;

    ArticleID getID() const;
    ArticleName getTitle() const;
    Author getAuthor() const;
    Body getBody() const;

private:
    /* Member variables */
    ArticleName title;
    Author author;
    Body body;
    ArticleID id;
};

#endif
