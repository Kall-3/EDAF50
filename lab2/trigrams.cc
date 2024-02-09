#include <algorithm>
#include <string>
#include <vector>
#include "trigrams.h"

using std::string;
using std::vector;

vector<string> trigrams(string& word)
{
    vector<string> trigrams;

    // Trandform to lowercase letters
    std::transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c){ return std::tolower(c); });
    
    // Number of trigrams for this word
    int nbr_trigrams = word.size() - 2;

    for (int i = 0; i < nbr_trigrams; i++)
    {
        // Pick trigram
        string tri = word.substr(i, 3);

        // Insertion
        int middle = trigrams.size() / 2;

        if (trigrams.empty())
        {
            trigrams.push_back(tri);
        }
        else {
            auto it = std::lower_bound(trigrams.begin(), trigrams.end(), tri);
            trigrams.insert(it, tri);
        }
    }

    return trigrams;
}

