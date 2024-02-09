#ifndef WORD_H
#define WORD_H

#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#include <functional>

class Word {
public:
    /* Member values */
    std::string word;
    int length;
    std::vector<std::string> trigrams;
    int nbr_trigrams;

	/* Creates a word w with the sorted trigrams t */
	Word(const std::string& line);

    /* Parse a string to a new word */
    void parse(const std::string& line, std::string& word, std::vector<std::string>& trigrams, int& nbr_trigrams);

    /* Overload equal operation */
    bool operator==(const Word& other) const {
        return this->word == other.word;
    }
	
	/* Returns the word */
	Word get_word() const;
	
	/* Returns how many of the trigrams in t that are present
	 in this word's trigram vector */
	unsigned int get_matches(const std::vector<std::string>& t) const;
private:
};

template<>
struct std::hash<Word> {
    size_t operator()(const Word& word) const {
        return std::hash<std::string>()(word.word);
    }
};

#endif
