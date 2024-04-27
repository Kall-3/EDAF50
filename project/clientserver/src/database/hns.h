#include <vector>
#include "article.h"
#include "enums.h"

class HashMap {
public:
    HashMap (size_t size);

    /* Basic hashmap functions */
	void insert(const ArticleName& host, const Article& address);
	bool remove(const ArticleName& host);
	Article* lookup(const ArticleName& host) const;

private:
    /* Member values */
    int size;
    float load_factor;
    float max_load_factor;
    std::vector<std::vector<std::pair<ArticleName, Article>>> articles;

    /* Private member functions */
    void rehash();
};
