#include <istream>
#include <ostream>

class TagRemover {
public:
    /* Member variables */
    std::string data;

    /* Member functions */
    TagRemover(std::istream& input);
    ~TagRemover() = default;

    void print(std::ostream& output);
private:

};
