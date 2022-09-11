#include <iostream>
#include <cstdlib>
#include "screen.h"

Screen::Screen(std::string t, std::vector<std::string> c){
    title = t;
    commands = c;
}

void Screen::printScreen(){
    this->clear();
    this->printLine(title);
    std::cout << std::endl;
    for(int i = 0; i < this->commands.size(); ++i)
        this->printLine(this->commands[i]);
    std::cout << std::endl;
    for(int i = 0; i < this->lines.size(); ++i)
        this->printLine(this->lines[i]);
}

void Screen::clear(){
    system("clear");
}

void Screen::printLine(std::string s){
    std::cout << s << std::endl;
}