#include "character.h"

Character::Character(){
    this->base_hp = 100;
    this->base_def = 50;
    this->base_atk = 25;
    this->hp = base_hp;
    this->updateStats();
}

void Character::updateStats(){
    final_hp = base_hp;
    final_def = base_def;
    final_atk = base_atk;
}

const int Character::actualHealth(){
    return hp;
}

void Character::attack(Character* target, int dmg){
    target->getAttacked(this->outputDamage(dmg));
}

void Character::getAttacked(const int dmg){
    hp -= this->inputDamage(dmg);
}

const int Character::outputDamage(const int dmg){
    return (int)(0.80*this->final_atk*dmg);
}

const int Character::inputDamage(const int dmg){
    return (dmg-(this->final_def*0.65));
}