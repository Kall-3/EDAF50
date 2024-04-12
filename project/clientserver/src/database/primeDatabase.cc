#include "database.h"
#include <unordered_map>

class PrimeDatabase : public DatabaseInterface {
public:
    /* unordered map with <group name, NewsGroup> */
    std::unordered_map<std::string, NewsGroup> groups;

        PrimeDatabase() = default();
};
