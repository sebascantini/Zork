#include "interface.h"
#include "environment.h"

void Environment::playerTurn(){
    int input = stoi(askForInput());
    while(this->isInputInvalid(input)){
        input = stoi(askForInput());
    }
    this->commands[input-1](this);
}

bool Environment::isInputInvalid(int input){
    return !(input >= 0 && input < this->commands.size() + 1);
}