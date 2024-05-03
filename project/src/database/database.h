#ifndef DATABASE_H
#define DATABASE_H

#include "enums.h"
#include "newsgroup.h"
#include <vector>

class DatabaseInterface {
protected:
    std::ostream& out;
    std::ostream& err;

public:
    // Constructor
    explicit DatabaseInterface(std::ostream& o, std::ostream& e) : out(o), err(e) {}
    virtual ~DatabaseInterface() {};

    virtual std::pair<ActionResult, std::vector<Newsgroup>> listNewsgroups() = 0;
    virtual ActionResult addNewsgroup(const NewsgroupName&) = 0;
    virtual ActionResult removeNewsgroup(const NewsgroupID&) = 0;
    virtual std::pair<ActionResult, std::vector<Article>> getArticles(const NewsgroupID&) = 0;
    virtual ActionResult newArticle(const NewsgroupID&, const ArticleName&, const Author&, const Body&) = 0;
    virtual ActionResult removeArticle(const NewsgroupID&, const ArticleID&) = 0;
    virtual std::pair<ActionResult, Article> getArticle(const NewsgroupID&, const ArticleID&) = 0;

private:
    virtual NewsgroupID getNextID() = 0;
};

#endif
