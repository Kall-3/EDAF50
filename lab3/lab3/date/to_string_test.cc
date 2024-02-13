#include <gtest/gtest.h>
#include "date.h"
#include "to_string.cc"

TEST(ToStringTest, TrivialEqualityTest) {
    double d = 1.234;
    Date today;
    std::string sd = toString(d);
    std::string st = toString(today);
}
