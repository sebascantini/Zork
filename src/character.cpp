#include "character.h"
#include <algorithm>

Character::~Character(){
    delete(this->weapon);
}

const std::string Character::getName(){
    return this->name;
}

const int Character::getHealth(){
    return this->health;
}

const int Character::getSpeed(){
    return this->speed;
}

const int Character::getCurrentHealth(){
    return this->current_health;
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