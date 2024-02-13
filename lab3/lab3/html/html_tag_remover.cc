#include <iostream>
#include "tagremover.h"

int main() {
    TagRemover tr(std::cin); // read from cin
    tr.print(std::cout); // print on cout
}
