#include "headers/access.h"

Access::Access(int index, std::pair<int, int> exit_position){
    this->name = "Access Point";
    this->symbol = 'A';
    this->exit_position = exit_position;
    this->index = index;
}

std::pair<int, int> Access::get_exit(){
    return this->exit_position;
}

int Access::get_index(){
    return this->index;
}

bool Access::isAccess(){
    return true;
}