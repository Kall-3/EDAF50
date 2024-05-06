#ifndef PRIME_DATABASE_H
#define PRIME_DATABASE_H

#include "newsgroup.h"
#include "database/database.h"

#include <memory>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

class PrimeDatabase : public DatabaseInterface {
public:
    PrimeDatabase() = default;
    ~PrimeDatabase() = default;
    std::pair<ActionResult, std::vector<std::pair<NewsgroupID, NewsgroupName>>> listNewsgroups() override;
    ActionResult addNewsgroup(const NewsgroupName&) override;
    ActionResult removeNewsgroup(const NewsgroupID&) override;
    std::pair<ActionResult, std::vector<std::pair<ArticleID, ArticleName>>> getArticles(const NewsgroupID&) override;
    ActionResult newArticle(const NewsgroupID&, const ArticleName&, const Author&, const Body&) override;
    ActionResult removeArticle(const NewsgroupID&, const ArticleID&) override;
    std::pair<ActionResult, std::tuple<ArticleName, Author, Body>> getArticle(const NewsgroupID&, const ArticleID&) override;

private:
    std::unordered_map<NewsgroupID, std::shared_ptr<Newsgroup>> groups;
    std::shared_ptr<Newsgroup> findNewsgroup(const NewsgroupID& name);

    /* Used to set up unique ID for next newsgroup */
    NewsgroupID getNextID();
    NewsgroupID nextID = 0;
};

#endif
