#include <vector>
#include <unordered_map>
#include "article.h"
#include "database/enums.h"

class Newsgroup {
public:
    /* New newsgroup*/
    Newsgroup(NewsgroupName name, NewsgroupID id);

    /* Remove newsgroup */
    ~Newsgroup() = default;

    /* Prints articles in newsgroup to std::out */
    std::pair<ActionResult, std::vector<Article>> getArticles();
    ActionResult newArticle(ArticleName, Author, Body);
    std::pair<ActionResult, Article> getArticle(const ArticleID&);
    ActionResult removeArticle(const ArticleID&);

    NewsgroupID getID();
    NewsgroupName getName();

private:
    /* Member values */
    NewsgroupName name;
    NewsgroupID id;
    /* unordered map with <id, article> */
    std::unordered_map<ArticleID, Article> articles;

    /* Used to set up unique ID for the next article */
    ArticleID getNextID();
    ArticleID nextID = 0;
};
