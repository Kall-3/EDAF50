#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& line)
{
    string word;
    vector<string> trigrams;
    int nbr_trigrams;
    // trigrams.resize(nbr_trigrams);

    parse(line, word, trigrams, nbr_trigrams);

    this->word = word;
    this->length = word.length();
    this->trigrams = trigrams;
}

void Word::parse(const string& line, string& word, vector<string>& trigrams, int& nbr_trigrams) {
        std::istringstream iss(line);

        iss >> word;

        iss >> nbr_trigrams;

        string trigram;
        while (iss >> trigram)
        {
            trigrams.push_back(trigram);
        }
}

Word Word::get_word() const {
	return this->word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
    // Two pointer approach
    unsigned int matches = 0;
    long unsigned int i = 0, j = 0;

    while(i < this->trigrams.size() && j < t.size())
    {
        if (this->trigrams[i] == t[j])
        {
            matches++;
            i++;
            j++;
        }
        else if (this->trigrams[i] < t[j])
        {
            i++;
        }
        else if (this->trigrams[i] > t[j])
        {
            j++;
        }
    }
	return matches;
}
