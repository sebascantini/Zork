
#include "headers/game.h"

void Game::moveUp(){
    if(this->moving)
        this->movePlayer(-1, 0);
    else
        this->selector = std::max(this->selector - 1, 0);
}

void Game::moveDown(){
    if(this->moving)
        this->movePlayer(1, 0);
    else
        this->selector = std::min(this->selector + 1, 2);
}

void Game::moveLeft(){
    if(this->moving)
        this->movePlayer(0, -1);
}

void Game::moveRight(){
    if(this->moving)
        this->movePlayer(0, 1);
}

void Game::options(){
    this->moving = !this->moving;
    this->moving ? this->selector = -1 : this->selector = 0;
}