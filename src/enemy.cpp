#include "enemy.h"
#include "player.h"

void Enemy::turn(){
   this->attack(player);
}