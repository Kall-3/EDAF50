#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

constexpr int WORDS_LENGTH = 25;
    
class Dictionary {
public:
    /* Member values */
    std::unordered_set<Word> words[25];

    /* Constructor */
	Dictionary();

    /* Member functions */
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
    int levenshtien_distance(const std::string& word1, const std::string& word2) const;
};

#endif
