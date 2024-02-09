#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>
#include <queue>

#include "word.h"
#include "dictionary.h"
#include "trigrams.h"

using std::string;
using std::vector;

Dictionary::Dictionary() {
    std::ifstream file("words.txt");
    if (!file.is_open())
    {
        std::cerr << "File not found!" << std::endl;
    }

    string line;
    while (std::getline(file, line))
    {
        Word new_word(line);
        this->words[new_word.length].insert(new_word);
    }
}

bool Dictionary::contains(const string& word) const {
    auto search = this->words[word.length()].find(word);
    return search != this->words[word.length()].end();
}

vector<string> Dictionary::get_suggestions(const string& const_word) const {

    auto comp = [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b)
    {
        return a.first > b.first;
    };

    std::priority_queue<std::pair<int, string>, vector<std::pair<int, string>>, decltype(comp)> suggestions(comp);
    string word = const_word;

    auto find_suggestions = [this, &suggestions](string word, int word_length)
    {
        vector<string> tri = trigrams(word);
        unsigned int nbr_trigrams = tri.size();
    
        for (const auto& element : this->words[word_length])
        {
            if (element.get_matches(tri) >= std::ceil(nbr_trigrams/2.0))
            {
                int cost = this->levenshtien_distance(word, element.word);

                if (suggestions.size() < 5) {
                    suggestions.push(std::make_pair(cost, element.word));
                } else if (cost < suggestions.top().first) {
                    suggestions.pop(); // TODO:
                    suggestions.push(std::make_pair(cost, element.word));
                }
            }
        }
    };

    find_suggestions(word, word.length());
    find_suggestions(word, word.length() + 1);
    find_suggestions(word, word.length() - 1);

    vector<string> result;
    while(!suggestions.empty())
    {
        result.push_back(suggestions.top().second);
        suggestions.pop();
    }
	return result;
}

int Dictionary::levenshtien_distance(const string& word1, const string& word2) const
{
    vector<vector<int>> distances(word1.length() + 1, vector<int>(word2.length() + 1));

    for (long unsigned int i = 0; i <= word1.length(); ++i)
    {
        distances[i][0] = i;
    }
    for (long unsigned int j = 0; j <= word2.length(); ++j)
    {
        distances[0][j] = j;
    }

    for (long unsigned int i = 1; i <= word1.length(); ++i)
    {
            for (long unsigned int j = 1; j <= word2.length(); ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    distances[i][j] = distances[i - 1][j - 1];
                }
                else
                {
                    distances[i][j] = std::min(
                        distances[i - 1][j] + 1,
                        std::min(
                            distances[i][j - 1] + 1,
                            distances[i - 1][j - 1] + 1)
                    );
                }
            }
        }
    
        return distances[word1.length()][word2.length()];
}

