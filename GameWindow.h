//
// Created by ciastek on 22.06.23.
//

#ifndef MYSFMLAPP_GAMEWINDOW_H
#define MYSFMLAPP_GAMEWINDOW_H

#include "Window.h"
#include "Game.h"

class GameWindow : protected Window{
private:
    std::string error_info;
    Game* game;
    sf::Text game_grid[GAME_GUESSES][WORD_LENGTH];
public:
    GameWindow(GameManager *gameManager, sf::RenderWindow* window, Game* game, int height, int width);
    void drawWindow() override;
};


#endif //MYSFMLAPP_GAMEWINDOW_H
