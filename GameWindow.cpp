//
// Created by ciastek on 22.06.23.
//

#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow(GameManager *gameManager, sf::RenderWindow *window, Game *game, int height, int width)
                        : Window(gameManager, window, height, width), game(game), error_info(" "){
}

void GameWindow::drawWindow() {
    if(game == nullptr)
        throw std::invalid_argument("game can not be a nullptr");
    char letter;
    bool added_new_letter = false;
    window->setTitle("In Game");
    window->setSize(sf::Vector2u(window_width, window_height));
    while(gameManager->isGameLast()){
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    gameManager->stopGame();
                    window->close();
                    break;
                case sf::Event::TextEntered:
                    letter = static_cast<char>(event.text.unicode);
                    if ('a' <= letter && letter <= 'z')
                        try {
                            game->insertLetter(letter);
                            added_new_letter = true;
                        }
                        catch (const std::out_of_range& e){
                            perror(e.what());
                            error_info = "You need to confirm you're\nanswer";
                        }
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Key::Enter){
                        try {
                            game->confirmGuess();
                        }
                        catch (const std::out_of_range& e){
                            perror(e.what());
                            error_info = "You are not ready to\nconfirm";
                        }
                    }
                    if (event.key.code == sf::Keyboard::Key::BackSpace){
                        try {
                            game->eraseLetter();
                        }
                        catch (const std::out_of_range& e){
                            perror(e.what());
                            error_info = "Can not erase more letters";
                        }
                    }
                    break;
                default:
                    break;
            }

        }
        if (added_new_letter){
            error_info = " ";
            added_new_letter = false;
        }
        window->clear();
        for(int i = 0; i < GAME_GUESSES; i++)
            for(int j = 0; j < WORD_LENGTH; j++){
                game_grid[i][j].setFont(this->normalTextFount);
                game_grid[i][j].setString(game->getLetter(i,j));
                game_grid[i][j].setCharacterSize(20);
                game_grid[i][j].setPosition(j*20 + 60, i*20 + 10);
                game_grid[i][j].setOutlineColor(sf::Color::Black);
                game_grid[i][j].setOutlineThickness(0.1);
                switch (game->getColor(i, j)) {
                    case YELLOW:
                        game_grid[i][j].setFillColor(sf::Color::Yellow);
                        break;
                    case GREEN:
                        game_grid[i][j].setFillColor(sf::Color::Green);
                        break;
                    default:
                        game_grid[i][j].setFillColor(sf::Color::White);
                        break;
                }
                window->draw(game_grid[i][j]);
        }

        sf::Text player_wrongs;
        player_wrongs.setFont(this->normalTextFount);
        player_wrongs.setString(error_info);
        player_wrongs.setCharacterSize(14);
        player_wrongs.setPosition(10, 150);
        player_wrongs.setOutlineColor(sf::Color::Black);
        player_wrongs.setOutlineThickness(0.1);
        window->draw(player_wrongs);

        window->display();
    }
}

