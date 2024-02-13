#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "tagremover.h"

using std::string;

TEST(HTMLTesting, ConstructorTest) {
    std::stringstream ss("Hello, <TAGGED HERE>world!");
    TagRemover tr(ss);

    ASSERT_EQ(tr.data, "Hello, world!");
}

TEST(HTMLTesting, OutputTest) {
    std::stringstream ss1("Hello, <TAGGED HERE AGAIN>world!");
    TagRemover tr(ss1);

    std::stringstream ss2;
    tr.print(ss2);

    ASSERT_EQ(ss2.str(), "Hello, world!") << "Wrong output, got: " << ss2.str() << ", expected: \"Hello, World!\"";
}

TEST(HTMLTesting, NewlineTest) {
    std::stringstream ss;
    ss  << "Hello, world!<Tag here\n"
        << "excedes multiple lines\n"
        << "and ends here maybe>third line";
    TagRemover tr(ss);

    ASSERT_EQ(tr.data, "Hello, world!\n\nthird line");
}

TEST(HTMLTesting, GivenLabTest) {
    std::ifstream fs("test.html");
    if (!fs.is_open()) {
        std::cerr << "File not found!" << std::endl;
    }
    TagRemover tr(fs);

    std::stringstream ss;
    ss  << "This is a line without a tag\n"
        << "This is  a line with one tag\n"
        << "And this  line has two tags \n"
        << "A line with a starting tag \n\n"
        << " which finished on this line \n"
        << "Special chars: <> &";
    ASSERT_EQ(tr.data, ss.str());
}
