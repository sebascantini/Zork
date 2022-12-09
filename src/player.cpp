#include "headers/interface.h"
#include "headers/player.h"

Player* player;

Player::Player(){
    this->name = "Player";
    this->symbol = 'P';
}

std::string Player::show(){
    return " " + this->name + "    ";
}

void initializePlayer(){
    player = new Player();
}

void deletePlayer(){
    delete(player);
}