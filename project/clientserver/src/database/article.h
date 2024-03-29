#include <ostream>
#include <string>
class Article {
public:
    /* Member variables */
    std::string title;
    std::string author;
    std::string body;

    /* New article */
    Article();

    /* Remove article */
    ~Article();

    /* Print article to std::ostream */
    void printArticle(std::ostream out);
};
