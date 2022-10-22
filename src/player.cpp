#include "headers/interface.h"
#include "headers/player.h"

Player* player;

Player::Player(){
    this->name = "Player";
    this->health = 100;
    this->defence = 20;
    this->strength = 25;
    this->speed = 50;
    this->current_health = this->health;
    this->weapon = new Weapon();
}

void Player::turn(Context* context){
    context->playerTurn();
}

std::string Player::show(){
    return " " + this->getName() + "    HP: " + std::to_string(this->getCurrentHealth()) + "/" + std::to_string(this->getMaxHealth());
}

void initializePlayer(){
    player = new Player();
}

void deletePlayer(){
    delete(player);
}