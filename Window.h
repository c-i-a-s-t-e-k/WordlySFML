//
// Created by ciastek on 22.06.23.
//

#ifndef MYSFMLAPP_WINDOW_H
#define MYSFMLAPP_WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "GameManager.h"
class Window {
protected:
    GameManager *gameManager;
    int window_height;
    int window_width;
    sf::RenderWindow* window;
    sf::Font normalTextFount;
    std::vector<sf::Drawable*> drawables;

    void addDrawable(sf::Drawable* drawable) {
        drawables.push_back(drawable);
    }
public:
    Window(GameManager* gameManager, sf::RenderWindow* window, int height, int width);

    virtual void drawWindow();
};


#endif //MYSFMLAPP_WINDOW_H
