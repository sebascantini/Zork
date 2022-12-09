#include "headers/object.h"

const std::string Object::get_name(){
    return this->name;
}

const char Object::get_symbol(){
    return this->symbol;
}

bool Object::isAccess(){
    return false;
}