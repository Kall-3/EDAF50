#include "database.h"
#include "database/enums.h"
#include <unordered_map>
#include <vector>

class PrimeDatabase : public DatabaseInterface {
public:
    PrimeDatabase();
    std::pair<ActionResult, std::vector<Newsgroup>> listNewsgroups() override;
    ActionResult addNewsgroup(const NewsgroupName&) override;
    ActionResult removeNewsgroup(const NewsgroupID&) override;
    std::pair<ActionResult, std::vector<Article>> listArticles(const NewsgroupID&) override;
    ActionResult newArticle(const NewsgroupID&, const ArticleName&, const Author&, const Body&) override;
    ActionResult removeArticle(const NewsgroupID&, const ArticleID&) override;
    std::pair<ActionResult, Article> getArticle(const NewsgroupID&, const ArticleID&) override;

private:
    NewsgroupID getNextID() override;
    std::size_t nextID = 0;
    std::unordered_map<NewsgroupID, Newsgroup*> groups;
    Newsgroup* findNewsgroup(const NewsgroupID& name);
};
