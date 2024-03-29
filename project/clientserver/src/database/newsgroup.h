#include <ostream>
#include <unordered_map>
#include "article.h"

class NewsGroup {
public:
    /* unordered map with <title, article> */
    std::unordered_map<std::string, Article> articles;

    /* New newsgroup*/
    NewsGroup();

    /* Remove newsgroup */
    ~NewsGroup();

    /* Prints articles in newsgroup to std::out */
    void listArticles();

    /* New article */
    void newArticle(std::string title, std::string author, std::string body);

    /* Print article to std::ostream */
    void printArticle(std::ostream out, std::string title);

    /* Remove article with title */
    void removeArticle(std::string title);
};
