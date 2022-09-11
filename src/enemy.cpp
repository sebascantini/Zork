#include "enemy.h"
#include "player.h"

std::string Enemy::turn(){
    return "Enemy attacked player for " + std::to_string(this->attack(player, 3));
}