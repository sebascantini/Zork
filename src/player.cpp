#include "interface.h"
#include "player.h"
#include <string>

Player::Player(){
    this->name = "Player";
    this->health = 100;
    this->defence = 20;
    this->strength = 25;
    this->speed = 50;
    this->current_health = this->health;
    this->weapon = new Weapon();
}

void Player::turn(Environment* environment){
    environment->playerTurn();
}