//
// Created by ciastek on 23.06.23.
//

#include "GameManager.h"
#include "StartWindow.h"
#include "GameWindow.h"

void GameManager::manageGame() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    StartWindow startWindow(this, &window, START_WIDOW_HEIGHT, START_WIDOW_WIDTH);
    Game* game = new Game();
    GameWindow gameWindow(this, &window, game, GAME_WIDOW_HEIGHT, GAME_WIDOW_WIDTH);

    while (window.isOpen()) {

        if (!isGameLast()) {
            game->restartGame();
            startWindow.drawWindow();
            continue;
        }

        checkGameResult(game);
        gameWindow.drawWindow();
    }
}

void GameManager::checkGameResult(Game* game) {
    switch (game->getGameResult()) {
        case WIN:
            wins++;
            stopGame();
            break;
        case LOSE:
            loses++;
            stopGame();
            break;
        case NOT_SETTLE:
            break;
        default:
            throw std::invalid_argument("unknown game result");
            break;
    }
}