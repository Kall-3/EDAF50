#ifndef DATABASE_H
#define DATABASE_H

#include "enums.h"

#include <tuple>
#include <vector>

class DatabaseInterface {
public:
    // Constructor
    virtual ~DatabaseInterface() {};

    virtual std::pair<ActionResult, std::vector<std::pair<NewsgroupID, NewsgroupName>>> listNewsgroups() = 0;
    virtual ActionResult addNewsgroup(const NewsgroupName&) = 0;
    virtual ActionResult removeNewsgroup(const NewsgroupID&) = 0;
    virtual std::pair<ActionResult, std::vector<std::pair<ArticleID, ArticleName>>> getArticles(const NewsgroupID&) = 0;
    virtual ActionResult newArticle(const NewsgroupID&, const ArticleName&, const Author&, const Body&) = 0;
    virtual ActionResult removeArticle(const NewsgroupID&, const ArticleID&) = 0;
    virtual std::pair<ActionResult, std::tuple<ArticleName, Author, Body>> getArticle(const NewsgroupID&, const ArticleID&) = 0;
};

#endif
