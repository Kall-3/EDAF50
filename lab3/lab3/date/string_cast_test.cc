#include <exception>
#include <gtest/gtest.h>
#include <iostream>
#include "string_cast.cc"
#include "date.h"

TEST(StringCastTest, FromInt) {
    std::string s = "103231419";
    int i = string_cast<int>(s);

    ASSERT_EQ(i, 103231419);
}

TEST(StringCastTest, FromDouble) {
    std::string s = "1.2345";
    double d = string_cast<double>(s);

    ASSERT_EQ(d, 1.2345);
}

TEST(StringCastTest, FromDateClass) {
    std::string s = "2015-01-10";
    Date d = string_cast<Date>(s);

    ASSERT_EQ(d.getYear(), 2015);
    ASSERT_EQ(d.getMonth(), 1);
    ASSERT_EQ(d.getDay(), 10);
}

TEST(StringCastTest, ExpectExceptionThrown) {
    std::string s1 = "123093";
    std::string s2 = "January first, 1999";

    EXPECT_THROW({
        try {
            Date d = string_cast<Date>(s1);
        } catch (const std::exception& e) {
            EXPECT_STREQ("Conversion failed", e.what());
            throw;
        }
    }, std::invalid_argument);
    EXPECT_THROW({
        try {
            Date d = string_cast<Date>(s2);
        } catch (const std::exception& e) {
            EXPECT_STREQ("Conversion failed", e.what());
            throw;
        }
    }, std::invalid_argument);
}
