#include "access.h"
#include "../../settings/symbols.h"

Access::Access(int index, std::pair<int, int> exit_position){
    this->id = index;
    this->name = "Access Point";
    this->exit_position = exit_position;
}

char Access::getSymbol(){
    return ACCESS_SYMBOL;
}

bool Access::isAccess(){
    return true;
}

std::pair<int, int> Access::getExit(){
    return this->exit_position;
}