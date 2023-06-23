//
// Created by ciastek on 22.06.23.
//

#ifndef MYSFMLAPP_STARTWINDOW_H
#define MYSFMLAPP_STARTWINDOW_H
#include "Window.h"
#include "GameManager.h"
#include <SFML/System.hpp>

class StartWindow : protected Window{
private:
    std::string inform_string[6] = {
            "Play \"Wordle\" by\n trying to\n guess a word \nwithin 6 attempts.\n",
"to attempt \nmust be a valid \n5-letter word.\n",
"The color of \nthe tiles will change \nto indicate how \nclose your word \nguessing is.\n",
"Letters written in \ngreen highlight are\n in the word and \nin the correct\n position.\n",
"Letters written in \nyellow are in \nthe word but i\nn the wrong position.\n",
"Letters written in \nwhite are not \nin the word at all.\n"};
    friend int getWins(GameManager& manager){return manager.wins;}
    friend int getLoses(GameManager& manager){return manager.loses;};
public:
    StartWindow(GameManager* gameManager, sf::RenderWindow* window, int height, int width);// : Window(window, height, width) {};
    void drawWindow() override;
};



#endif //MYSFMLAPP_STARTWINDOW_H
