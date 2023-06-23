//
// Created by ciastek on 23.06.23.
//

#ifndef MYSFMLAPP_GAME_H
#define MYSFMLAPP_GAME_H

#include <string>
#include "Word.h"
#include "appPara.h"
#include "StringFactory.h"


enum GameResult {
    NOT_SETTLE = 2,
    WIN = 1,
    LOSE = 0
};

class Game {
private:
    StringFactory* stringFactory;
    Word* words;
    int current_letter;
    int current_guess;
    std::string password;
    GameResult gameResult;
public:
    GameResult getGameResult(){return gameResult;}
    void restartGame();
    void insertLetter(char letter);
    void eraseLetter();
    void confirmGuess();
    char getLetter(int guess, int idx) const;
    TileColor getColor(int guess, int idx) const;
    explicit Game();
    ~Game(){delete[] words;}
};


#endif //MYSFMLAPP_GAME_H
