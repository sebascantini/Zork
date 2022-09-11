#include "character.h"
#include <algorithm>

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

const int Character::attack(Character* target, int dmg){
    return target->getAttacked(this->outputDamage(dmg));
}

const int Character::getAttacked(const int dmg){
    int final_dmg = inputDamage(dmg);
    hp -= final_dmg;
    return final_dmg;
}

const int Character::outputDamage(const int dmg){
    return std::max(0, (int)(0.80*this->final_atk*dmg));
}

const int Character::inputDamage(const int dmg){
    return std::max(0, (int)(dmg-(this->final_def*0.65)));
}