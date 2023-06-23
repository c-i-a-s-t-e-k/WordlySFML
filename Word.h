//
// Created by ciastek on 23.06.23.
//

#ifndef MYSFMLAPP_WORD_H
#define MYSFMLAPP_WORD_H
#include "LetterTile.h"
#include <string>
#include <set>



class Word {
private:
    int length;
    LetterTile* letters;
    friend void setColor(LetterTile& letterTile, TileColor color){letterTile.color = color;}
public:
    void clean();
    bool checkCorrespondence(std::string word);
    Word(int length=0) : length(length) {
        if(length > 0)
            letters = new LetterTile[length];
        else
            letters = nullptr;
    }

    ~Word() {
        delete[] letters;
    }

    Word(const Word& other) : length(other.length) {
        letters = new LetterTile[length];
        for (int i = 0; i < length; i++) {
            letters[i] = other.letters[i];
        }
    }

    Word(Word&& other) noexcept : length(other.length), letters(other.letters) {
        other.length = 0;
        other.letters = nullptr;
    }

    Word& operator=(const Word& other) {
        if (this == &other) {
            return *this;
        }

        delete[] letters;

        length = other.length;
        letters = new LetterTile[length];
        for (int i = 0; i < length; i++) {
            letters[i] = other.letters[i];
        }

        return *this;
    }

    Word& operator=(Word&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete[] letters;

        length = other.length;
        letters = other.letters;

        other.length = 0;
        other.letters = nullptr;

        return *this;
    }
    LetterTile& operator[](int index) {
        if (index >= 0 && index < length) {
            return letters[index];
        } else {
            throw std::out_of_range("Invalid index");
        }
    }

    const LetterTile& operator[](int index) const {
        if (index >= 0 && index < length) {
            return letters[index];
        } else {
            throw std::out_of_range("Invalid index");
        }
    }
};

#endif //MYSFMLAPP_WORD_H
