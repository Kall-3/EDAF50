#include <iostream>
#include <string>
#include <vector>
#include "trigrams.h"

using std::vector;
using std::string;

using std::cout;
using std::endl;

int main ()
{
    string word;
    while (std::cin >> word)
    {
        if (word.size() > 2)
        {
            vector<string> res = trigrams(word);
            cout << word << " " << word.size() - 2;
            for (string elem : res)
            {
                cout << " " << elem;
            }
            cout << endl;
        }
        else
        {
            cout << word << " 0" << endl;
        }
    }
    return 0;
}
