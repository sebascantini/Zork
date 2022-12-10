#include "headers/interface.h"
#include "headers/player.h"
#include "headers/symbols.h"

Player* player;

Player::Player(){
    this->name = "Player";
    this->symbol = PLAYER_SYMBOL;
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