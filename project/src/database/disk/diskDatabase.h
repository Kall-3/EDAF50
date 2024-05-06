#ifndef DISK_DATABASE_H
#define DISK_DATABASE_H

#include "database/database.h"
#include "database/enums.h"

#ifndef PROJECT_ROOT
#define PROJECT_ROOT "" // Defined in CMake, compiler flag, should be the path to the project
#endif

#include <tuple>
#include <vector>
#include <filesystem>

using namespace std::filesystem;

class DiskDatabase : public DatabaseInterface {
public:
    DiskDatabase();
    ~DiskDatabase() = default;
    std::pair<ActionResult, std::vector<std::pair<NewsgroupID, NewsgroupName>>> listNewsgroups() override;
    ActionResult addNewsgroup(const NewsgroupName&) override;
    ActionResult removeNewsgroup(const NewsgroupID&) override;
    std::pair<ActionResult, std::vector<std::pair<ArticleID, ArticleName>>> getArticles(const NewsgroupID&) override;
    ActionResult newArticle(const NewsgroupID&, const ArticleName&, const Author&, const Body&) override;
    ActionResult removeArticle(const NewsgroupID&, const ArticleID&) override;
    std::pair<ActionResult, std::tuple<ArticleName, Author, Body>> getArticle(const NewsgroupID&, const ArticleID&) override;

private:
    path root = PROJECT_ROOT "/news_database/";

    /* Used to set up unique ID for next newsgroup */
    void writeNextNewsgroupID(int id);
    NewsgroupID getNextNewsgroupID();
    void writeNextArticleID(path newsgroup_path, int id);
    ArticleID getNextArticleID(path newsgroup_path);
};

#endif
