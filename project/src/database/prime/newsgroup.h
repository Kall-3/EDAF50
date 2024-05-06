#ifndef NEWSGROUP_H
#define NEWSGROUP_H

#include "article.h"
#include "database/enums.h"

#include <memory>
#include <vector>
#include <unordered_map>

class Newsgroup {
public:
    /* New newsgroup*/
    Newsgroup(NewsgroupName name, NewsgroupID id);

    /* Remove newsgroup */
    ~Newsgroup() = default;

    /* Prints articles in newsgroup to std::out */
    std::pair<ActionResult, std::vector<std::pair<ArticleID, ArticleName>>> getArticles();
    ActionResult newArticle(ArticleName, Author, Body);
    std::pair<ActionResult, std::tuple<ArticleName, Author, Body>> getArticle(const ArticleID&);
    ActionResult removeArticle(const ArticleID&);

    NewsgroupID getID() const;
    NewsgroupName getName() const;

private:
    /* Member values */
    NewsgroupName name;
    NewsgroupID id;
    /* unordered map with <id, article> */
    std::unordered_map<ArticleID, std::shared_ptr<Article>> articles;

    /* Used to set up unique ID for the next article */
    ArticleID getNextID();
    ArticleID nextID = 0;
};

#endif