#include "character.h"
#include <algorithm>

Character::Character(){
    this->health = 100;
    this->defence = 20;
    this->strength = 25;
    this->speed = 50;
    this->current_health = this->health;
    this->weapon = new Weapon();
}

Character::~Character(){
    delete(this->weapon);
}

const int Character::getCurrentHealth(){
    return this->current_health;
}

const int Character::getSpeed(){
    return this->speed;
}

void Character::attack(Character* target){
    target->getAttacked(this->outputDamage());
}

void Character::getAttacked(const int damage){
    int final_damage = inputDamage(damage);
    this->current_health -= final_damage;
}

const int Character::outputDamage(){
    return std::max(0, this->weapon->damage() + this->strength);
}

const int Character::inputDamage(const int damage){
    return std::max(0, (int)(damage-this->defence));
}