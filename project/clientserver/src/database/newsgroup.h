#include <vector>
#include <unordered_map>
#include "article.h"
#include "enums.h"

class Newsgroup {
public:
    /* New newsgroup*/
    Newsgroup(NewsgroupName name);

    /* Remove newsgroup */
    ~Newsgroup();

    /* Prints articles in newsgroup to std::out */
    std::pair<ActionResult, std::vector<Article>> getArticles();
    ActionResult newArticle(ArticleName, Author, Body);
    std::pair<ActionResult, Article> getArticle(const ArticleID&);
    ActionResult removeArticle(const ArticleID&);

private:
    /* Member values */
    static size_t newsgroup_counter;
    std::size_t identification_number;
    std::string name;
    /* unordered map with <id, article> */
    std::unordered_map<ArticleID, Article> articles;
};

size_t Newsgroup::newsgroup_counter = 0;

