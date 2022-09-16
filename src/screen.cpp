#include <iostream>
#include <cstdlib>
#include "screen.h"

void Screen::print(){
    system("clear");

    for(int i = 0; i < this->lines.size(); ++i)
        this->printLine(this->lines[i]);
    std::cout << std::endl;
}

void Screen::printLine(std::string s){
    std::cout << s << std::endl;
}