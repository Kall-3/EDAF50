#ifndef PRIMEDATABASE_H
#define PRIMEDATABASE_H

#include "database.h"
#include "enums.h"
#include <unordered_map>
#include <vector>

class PrimeDatabase : public DatabaseInterface {
public:
    explicit PrimeDatabase(std::ostream& o, std::ostream& e) : DatabaseInterface(o, e) {}
    ~PrimeDatabase() = default;
    std::pair<ActionResult, std::vector<Newsgroup>> listNewsgroups() override;
    ActionResult addNewsgroup(const NewsgroupName&) override;
    ActionResult removeNewsgroup(const NewsgroupID&) override;
    std::pair<ActionResult, std::vector<Article>> getArticles(const NewsgroupID&) override;
    ActionResult newArticle(const NewsgroupID&, const ArticleName&, const Author&, const Body&) override;
    ActionResult removeArticle(const NewsgroupID&, const ArticleID&) override;
    std::pair<ActionResult, Article> getArticle(const NewsgroupID&, const ArticleID&) override;

private:
    std::unordered_map<NewsgroupID, Newsgroup*> groups;
    Newsgroup* findNewsgroup(const NewsgroupID& name);

    /* Used to set up unique ID for next newsgroup */
    NewsgroupID getNextID() override;
    NewsgroupID nextID = 0;
};

#endif
