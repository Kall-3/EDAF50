#ifndef DATABASE_H
#define DATABASE_H

#include "enums.h"
#include "newsgroup.h"
#include <ostream>
#include <vector>

class DatabaseInterface {
protected:
    std::ostream& out;
    std::ostream& err;

public:
    // Constructor
    explicit DatabaseInterface(std::ostream& out, std::ostream& err) : out(out), err(err) {}

    // Virtual destructor - to allow derived class destructors to be called
    virtual ~DatabaseInterface() {}

    /* List newsgroups in database */
    virtual std::pair<ActionResult, std::vector<Newsgroup>> listNewsgroups();

    /* Add empty newsgroup */
    virtual ActionResult addNewsgroup(const NewsgroupName&);

    /* Remove newsgroup and contained articles */
    virtual ActionResult removeNewsgroup(const NewsgroupID&);

    /* List articles in newsgroup */
    virtual std::pair<ActionResult, std::vector<Article>> listArticles(const NewsgroupID&); // TODO: return type containing articles

    /* New article */
    virtual ActionResult newArticle(const NewsgroupID&, const ArticleName&, const Author&, const Body&);

    /* Remove article with title */
    virtual ActionResult removeArticle(const NewsgroupID&, const ArticleID&);

    /* Print article to out */
    virtual std::pair<ActionResult, Article> getArticle(const NewsgroupID&, const ArticleID&);

private:
    virtual NewsgroupID getNextID();
};


#endif
