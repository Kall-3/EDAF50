#include <sstream>
#include <stdexcept>
#include <string>

template <typename T>
T string_cast(const std::string& str) {
    std::istringstream iss(str);
    T value;
    iss >> value;

    if (!iss.eof() || iss.fail()) {
        throw std::invalid_argument("Conversion failed");
    }

    return value;
}
