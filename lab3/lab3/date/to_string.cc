#ifndef TOSTRING
#define TOSTRING

#include <sstream>

template <typename T>
std::string toString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif
