#include "tagremover.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <regex>

using std::string;

TagRemover::TagRemover(std::istream& input) {
    // Regex for HTML tags
    std::stringstream result;
    string line;
    bool first_line = true;
    bool in_tag = false;

    std::regex startTagPattern("<[^>]*$"); // starts with '<', not ending with '>'
    std::regex endTagPattern("^[^<]*>");    // ends with '>', not starting with '<'
    std::regex fullTagPattern("<[^>]*>");   // contains '<' and '>'

    while (std::getline(input, line)) {
        if (!first_line) {
            result << "\n";
        }

        if (in_tag) {
            if (std::regex_search(line, endTagPattern)) {
                in_tag = false;
                line = std::regex_replace(line, endTagPattern, "");
                // Check for remaining tags in this line
                if (std::regex_search(line, startTagPattern)) {
                    in_tag = true;
                    line = std::regex_replace(line, startTagPattern, "");
                } else if (std::regex_search(line, fullTagPattern)) {
                    line = std::regex_replace(line, fullTagPattern, "");
                }
            } else {
                continue;
            }
        } else {
            if (std::regex_search(line, startTagPattern)) {
                in_tag = true;
                line = std::regex_replace(line, startTagPattern, "");
            } else if (std::regex_search(line, fullTagPattern)) {
                line = std::regex_replace(line, fullTagPattern, "");
            }
        }

        std::regex lessThanTag("&lt;");
        std::regex greaterThanTag("&gt;");
        std::regex nonBreakingSpaceTag("&nbsp;");
        std::regex ampersandTag("&amp;");

        line = std::regex_replace(line, lessThanTag, "<");
        line = std::regex_replace(line, greaterThanTag, ">");
        line = std::regex_replace(line, nonBreakingSpaceTag, " ");
        line = std::regex_replace(line, ampersandTag, "&");

        result << line;
        first_line = false;
    }

    this->data = result.str();
}

void TagRemover::print(std::ostream& out) {
    out << this->data;
}
