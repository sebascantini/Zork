#include "headers/access.h"
#include "headers/symbols.h"

Access::Access(int index, std::pair<int, int> exit_position){
    this->name = "Access Point";
    this->symbol = ACCESS_SYMBOL;
    this->exit_position = exit_position;
    this->id = index;
}

std::pair<int, int> Access::get_exit(){
    return this->exit_position;
}

bool Access::isAccess(){
    return true;
}