//
// Created by ciastek on 22.06.23.
//

#include "appPara.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

Window::Window(GameManager *gameManager, sf::RenderWindow* window, int height, int width)
        :window_height(height), window_width(width), gameManager(gameManager){
    window->setSize(sf::Vector2u(width, height));
    this->window = window;
    if (!normalTextFount.loadFromFile(path_to_fount)) {
        throw std::runtime_error("fount not loaded, check path_to_fount variable in appPara.h");
    }
}

void Window::drawWindow() {
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    exit(EXIT_SUCCESS);
                default:
                    break;
            }
        }
        window->clear();
        for (const auto& drawable : this->drawables) {
            window->draw(*drawable);
        }
        window->display();
}
