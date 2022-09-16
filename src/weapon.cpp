#include "weapon.h"

Weapon::Weapon(){
    this->base_damage = 15;
}

const int Weapon::damage(){
    return this->base_damage;
}