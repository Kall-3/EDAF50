#ifndef DATABASE_ENUMS
#define DATABASE_ENUMS

#include <cstddef>
#include <string>

using ArticleName = std::string;
using ArticleID = std::size_t;
using NewsgroupName = std::string;
using NewsgroupID = std::size_t;
using Author = std::string;
using Body = std::string;

enum class ActionResult {
    ACCEPTED            = 0,
    NG_ALREADY_EXISTS   = 1,
    NG_DOES_NOT_EXIST   = 2,
    ART_DOES_NOT_EXIST  = 3
};

#endif
