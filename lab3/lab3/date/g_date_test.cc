#include <gtest/gtest.h>
#include <sstream>
#include "date.h"

TEST(DateTest, ConstructorAndGetTest) {
    Date birthday(1999, 5, 28);
    Date random(1225, 8, 3);
    Date annoying(999, 04, 02);

    ASSERT_EQ(birthday.getYear(), 1999);
    ASSERT_EQ(birthday.getMonth(), 5);
    ASSERT_EQ(birthday.getDay(), 28);
    ASSERT_EQ(random.getYear(), 1225);
    ASSERT_EQ(random.getMonth(), 8);
    ASSERT_EQ(random.getDay(), 3);
    ASSERT_EQ(annoying.getYear(), 999);
    ASSERT_EQ(annoying.getMonth(), 4);
    ASSERT_EQ(annoying.getDay(), 2);
}

TEST(DateTest, NextDateTest) {
    Date birthday(1999, 5, 28);
    birthday.next();
    Date endOfMonth(1999, 5, 31);
    endOfMonth.next();
    Date endOfYear(1999, 12, 31);
    endOfYear.next();

    ASSERT_EQ(birthday.getYear(), 1999);
    ASSERT_EQ(birthday.getMonth(), 5);
    ASSERT_EQ(birthday.getDay(), 29);
    ASSERT_EQ(endOfMonth.getYear(), 1999);
    ASSERT_EQ(endOfMonth.getMonth(), 6);
    ASSERT_EQ(endOfMonth.getDay(), 1);
    ASSERT_EQ(endOfYear.getYear(), 2000);
    ASSERT_EQ(endOfYear.getMonth(), 1);
    ASSERT_EQ(endOfYear.getDay(), 1);
}

TEST(DateTest, InStreamTest) {
    std::stringstream ss("2015-02-04");

    Date d(3502, 05, 17);
    ss >> d;

    ASSERT_EQ(d.getYear(), 2015);
    ASSERT_EQ(d.getMonth(), 2);
    ASSERT_EQ(d.getDay(), 4);
}

TEST(DateTest, FailingInStreamTest) {
    std::stringstream ss1("-05-242");
    std::stringstream ss2("-3- 02 - 17");

    Date d1(1, 1, 1);
    ss1 >> d1;
    Date d2(1, 1, 1);
    ss2 >> d2;

    ASSERT_EQ(d1.getYear(), 1);
    ASSERT_EQ(d1.getMonth(), 1);
    ASSERT_EQ(d1.getDay(), 1);
    ASSERT_EQ(d2.getYear(), 1);
    ASSERT_EQ(d2.getMonth(), 1);
    ASSERT_EQ(d2.getDay(), 1);
}

TEST(DateTest, OutStreamTest) {
    std::stringstream ss1;
    ss1 << "2014-03-03";

    Date d(2014, 3, 3);
    std::stringstream ss2;
    ss2 << d;

    ASSERT_EQ(ss1.str(), ss2.str());
}

TEST(DateTest, HarderOutStreamTest) {
    std::stringstream si1("0050-03-03");
    std::stringstream si2("0500-03-03");

    Date d1(50, 3, 3);
    std::stringstream so1;
    so1 << d1;
    Date d2(500, 3, 3);
    std::stringstream so2;
    so2 << d2;

    ASSERT_EQ(si1.str(), so1.str());
    ASSERT_EQ(si2.str(), so2.str());
}
