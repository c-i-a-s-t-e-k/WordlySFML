#include <thread>
#include "StartWindow.h"

StartWindow::StartWindow(GameManager* gameManager, sf::RenderWindow* window, int height, int width)
                : Window(gameManager,window, height, width){
}

void StartWindow::drawWindow(){
    int i = 0;
    bool isRunningThread = true;
    std::thread thread([&]() {
        while (isRunningThread) {
            i++;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });
    thread.detach();

    window->setSize(sf::Vector2u(window_width, window_height));
    while (!gameManager->isGameLast())
    {
        sf::Text wins_loses_info;
        wins_loses_info.setFont(this->normalTextFount);

        wins_loses_info.setString("wins: " + std::to_string(getWins(*gameManager)) + ", loses: " + std::to_string(getLoses(*gameManager)));
        wins_loses_info.setCharacterSize(24);
        wins_loses_info.setPosition(10, 170);
        wins_loses_info.setOutlineThickness(0.1);
        wins_loses_info.setOutlineColor(sf::Color::Black);
        addDrawable(&wins_loses_info);

        sf::Text player_prompt;
        player_prompt.setFont(this->normalTextFount);
        player_prompt.setString("Press ENTER to start");
        player_prompt.setCharacterSize(14);
        player_prompt.setPosition(10, 150);
        player_prompt.setOutlineThickness(0.1);
        player_prompt.setOutlineColor(sf::Color::Black);
        addDrawable(&player_prompt);


        sf::Text info_text;
        info_text.setFont(this->normalTextFount);
        info_text.setString(this->inform_string[i % 6]);
        info_text.setCharacterSize(19);
        info_text.setStyle(sf::Text::Bold);
        info_text.setOutlineThickness(0.1);
        info_text.setOutlineColor(sf::Color::Black);
        addDrawable(&info_text);

        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    isRunningThread = false;
                    gameManager->startGame();
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Key::Enter){
                        isRunningThread = false;
                        gameManager->startGame();
                    }
                    break;
                default:
                    break;
            }

        }
        window->clear();
        for (const auto& drawable : drawables) {
            window->draw(*drawable);
        }
        window->display();

    }
}

