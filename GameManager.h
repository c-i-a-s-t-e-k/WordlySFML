//
// Created by ciastek on 23.06.23.
//

#ifndef MYSFMLAPP_GAMEMANAGER_H
#define MYSFMLAPP_GAMEMANAGER_H

#include "appPara.h"
#include "Game.h"

class GameManager{
private:
    bool is_game_starting = false;
    int wins = 0;
    int loses = 0;

    void checkGameResult(Game* game);
public:
    void startGame(){ is_game_starting = true;};
    void stopGame(){ is_game_starting = false;};
    bool isGameLast() const {return is_game_starting;};

    friend int getWins(GameManager& manager);
    friend int getLoses(GameManager& manager);

    void manageGame();
};


#endif //MYSFMLAPP_GAMEMANAGER_H
