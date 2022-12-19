#include "player.h"
#include "../../general/settings/symbols.h"

Player* player;

Player::Player(){
    this->name = "Player";
}

char Player::getSymbol(){
    return PLAYER_SYMBOL;
}

std::string Player::show(){
    return " " + this->name + "    ";
}

void initializePlayer(){
    player = new Player();
}

void finalizePlayer(){
    delete(player);
}