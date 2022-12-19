#include "menuselector.h"

MenuSelector::MenuSelector(int start, int max){
    this->value = start;
    this->max = max;
}

int MenuSelector::getValue(){
    return this->value;
}

void MenuSelector::toggle(){
    this->value = this->value == -1 ? 0 : -1;
}

void MenuSelector::increase(){
    this->value = std::min(this->max, this->value + 1);
}

void MenuSelector::decrease(){
    this->value = std::max(0, this->value - 1);
}

std::string MenuSelector::show (int value){
    return (this->value == value) ? "->" : "";
}