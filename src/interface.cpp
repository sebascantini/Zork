#include <iostream>
#include <cstdlib>
#include "environment.h"
#include "interface.h"

std::string askForInput(){
    std::string input;
    std::cin >> input;
    return input;
}

void askForCommand(){
    int input = stoi(askForInput());
    while(input < 1 || input > commands.size()){
        input = stoi(askForInput());
    }
    commands[input-1](environment);
}

void printLine(std::string s){
    std::cout << s << std::endl;
}

void print(std::vector<std::string> screen){
    system("clear");

    for(int i = 0; i < screen.size(); ++i)
        printLine(screen[i]);
    std::cout << std::endl;
}