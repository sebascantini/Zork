#include "character.h"
#include "../../config/symbols.h"

char Character::getSymbol(){
    return CHARACTER_SYMBOL;
}

bool Character::isCharacter(){
    return true;
}

void Character::increaseHealth(int amount){
    this->health += amount;
}