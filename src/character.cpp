#include "character.h"
#include <iostream>

Character::Character(){
    this->max_health = 100;
    this->defence = 50;
    this->attack = 25;
    this->health = max_health;
}

const int Character::actualHealth(){
    return health;
}

int Enemy::turn(){
    std::cout << "enemy turn\n";
    return 0;
}

int Player::turn(){
    std::cout << "player turn\n";
    return 0;
}