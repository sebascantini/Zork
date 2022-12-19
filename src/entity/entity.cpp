#include "entity.h"

const int Entity::getID() {
    return this->id;
}

const std::string Entity::getName() {
    return this->name;
}

char Entity::getSymbol() {
    return '@';
}

std::pair<int, int> Entity::getExit() {
    return {0, 0};
}

bool Entity::isAccess() {
    return false;
}

bool Entity::isItem() {
    return false;
}

bool Entity::isCharacter() {
    return false;
}