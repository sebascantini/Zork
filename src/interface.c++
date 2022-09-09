#include <iostream>
#include <cstdlib>
#include "interface.h"

void clear(){
    system("clear");
}

std::string askForInput(){
    std::string input;
    std:: cin >> input;
    return input;
}

void printStream(std::string s){
    std::cout << s << std::endl;
}