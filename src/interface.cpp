#include <iostream>
#include "context.h"
#include "interface.h"

std::string askForInput(){
    std::string input;
    std::cin >> input;
    return input;
}

const int askForInt(int max){
    int input = stoi(askForInput());
    while(input < 1 || input > max)
        input = stoi(askForInput());
    return input;
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