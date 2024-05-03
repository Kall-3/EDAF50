#include "database.h"
#include <unordered_map>

class DiskDatabase : public DatabaseInterface {
public:
    /* unordered map with <group name, NewsGroup> */
    std::unordered_map<std::string, Newsgroup> groups;

};