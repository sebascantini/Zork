#include "enemy.h"
#include "player.h"

Enemy::Enemy(){
   this->name = "Enemy";
    this->health = 100;
    this->defence = 20;
    this->strength = 25;
    this->speed = 50;
    this->current_health = this->health;
    this->weapon = new Weapon();
}

void Enemy::turn(Environment* environment){
   this->attack(player);
}