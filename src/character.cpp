#include <algorithm>
#include "headers/character.h"
#include "headers/player.h"

Character::Character(){
   this->name = "Character";
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

const bool Character::isAlive(){
    return this->current_health > 0;
}

void Character::heal(int amount){
    this->current_health = std::min(this->current_health + amount, this->health);
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

void Character::turn(Context* context){
   this->attack(player);
}