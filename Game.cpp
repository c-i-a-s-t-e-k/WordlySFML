//
// Created by ciastek on 23.06.23.
//

#include "Game.h"
#include <iostream>

Game::Game()  : gameResult(NOT_SETTLE), words(new Word[GAME_GUESSES]), current_guess(0)
                            , current_letter(0), stringFactory(new StringFactory){
    for(int i = 0; i < GAME_GUESSES; i++){
        words[i] = Word(WORD_LENGTH);
    }
}

void Game::restartGame() {
    gameResult = NOT_SETTLE;
    for (int i = 0; i < current_guess;i++)
        words[i].clean();
    current_guess = 0;
    current_letter = 0;
    password = stringFactory->generateRandomWord();
    std::cout<<password<<std::endl;
}

void Game::insertLetter(char letter) {
    if (current_letter < WORD_LENGTH){
        if(current_letter < 0) current_letter = 0;
        words[current_guess][current_letter] = letter;
        current_letter ++;
    } else{
        throw std::out_of_range("too much letters have been given");
    }
}

void Game::eraseLetter() {
    if (current_letter <= WORD_LENGTH){
        words[current_guess][--current_letter].refreshLetterTile();
    } else{
        throw std::out_of_range("index < 0");
    }
}

void Game::confirmGuess() {
    if (current_letter == WORD_LENGTH){
        if(words[current_guess].checkCorrespondence(password))
            gameResult=WIN;
        current_letter = 0;
        if(++current_guess == GAME_GUESSES)
            gameResult=LOSE;
    }else{
        throw std::out_of_range("not enough letters have been given");
    }

}

char Game::getLetter(int guess, int idx) const {
    return words[guess][idx].getLetter();
}
TileColor Game::getColor(int guess, int idx) const {
    return words[guess][idx].getColor();
}



