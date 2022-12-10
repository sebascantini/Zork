#include "headers/object.h"

const std::string Object::get_name(){
    return this->name;
}

const char Object::get_symbol(){
    return this->symbol;
}

const int Object::get_id(){
    return this->id;
}

bool Object::isAccess(){
    return false;
}

bool Object::isItem(){
    return false;
}
