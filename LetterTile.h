#ifndef MYSFMLAPP_LETTERTILE_H
#define MYSFMLAPP_LETTERTILE_H

#include <stdexcept>
#include <SFML/Graphics.hpp>
enum TileColor{
    WHITE = 0,
    YELLOW = 1,
    GREEN = 2
};

class LetterTile {
private:
    char letter;
    TileColor color;
    friend void setColor(LetterTile& letterTile, TileColor color);
public:
    LetterTile(char letter): color(WHITE){
        if (!isalpha(letter)) {
            throw std::invalid_argument("Invalid value");
        }
        this->letter = letter;
    }

    LetterTile() : letter('\0'), color(WHITE){}

    LetterTile& operator=(const char& other_letter) {
        if(isalpha(other_letter))
            this->letter = other_letter;
        else
            throw std::invalid_argument("thi is not a letter");
        return *this;
    }
    char getLetter() const{return letter;}
    char refreshLetterTile() {letter='\0'; color=WHITE;}
    TileColor getColor() const{return color;}

};



#endif //MYSFMLAPP_LETTERTILE_H