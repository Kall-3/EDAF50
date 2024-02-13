#include <istream>
#include <ostream>

class TagRemover {
public:
    /* Member variables */
    std::string data;

    /* Member functions */
    TagRemover(std::istream& input);
    ~TagRemover();
    TagRemover(TagRemover &&) = default;
    TagRemover(const TagRemover &) = default;
    TagRemover &operator=(TagRemover &&) = default;
    TagRemover &operator=(const TagRemover &) = default;

    void print(std::ostream& output);
private:
    
};
