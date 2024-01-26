#include <iostream>
#include <string>
#include "coding.h"

using std::cout;
using std::endl;

int main()
{
    std::string s;
    while(std::getline(std::cin, s))
    {
        for (unsigned char c : s)
        {
            cout << decode(c);
        }
        cout << endl;
    }
    return 0;
}
