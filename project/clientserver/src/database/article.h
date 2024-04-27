#include <cstddef>
#include <ostream>
#include <string>
#include "enums.h"

static size_t article_counter = 0;

class Article {
public:
    /* New article */
    Article(ArticleName title, Author author, Body body);

    /* Remove article */
    ~Article();

    /* Print article to std::ostream */
    void printArticle(std::ostream out);

    std::size_t getID();

private:
    /* Member variables */
    std::string title;
    std::string author;
    std::string body;
    std::size_t identification_number;

    std::size_t getNextID();
};
