//
// Created by ciastek on 23.06.23.
//

#include "Word.h"

std::set<char> stringToSet(const std::string& word) {
    std::set<char> letters;
    for (char letter : word) {
        letters.insert(letter);
    }
    return letters;
}

bool Word::checkCorrespondence(std::string word) {
    int count = 0;
    std::set<char> word_set = stringToSet(word);
    for (int i = 0; i < length;i ++) {
        if (word[i] == this->letters[i].getLetter()) {
            setColor(letters[i], GREEN);
            count++;
            continue;
        }
        if (word_set.count(letters[i].getLetter()) > 0)
            setColor(letters[i], YELLOW);
    }
    return count == length;
}

void Word::clean() {
    for(int i = 0; i < length; i++){
        letters[i].refreshLetterTile();
    }
}
