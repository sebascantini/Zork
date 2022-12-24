#include "context.h"
#include "../interface.h"
#include "../settings/settings.h"

void Context::run(){
    this->is_active = true;
    while(this->is_active){
        this->getInput();
        this->show();
    }
}

const int Context::getKey(){
    return (int) getch();
}

void Context::getInput(){
    int input;
    do{
        input = this->getKey();
    }while(settings->getInputCode(input) == -1);
    switch(settings->getInputCode(input)){
        case KEY_CODE_UP:
            this->moveUp();
            break;
        case KEY_CODE_DOWN:
            this->moveDown();
            break;
        case KEY_CODE_LEFT:
            this->moveLeft();
            break;
        case KEY_CODE_RIGHT:
            this->moveRight();
            break;
        case KEY_CODE_SELECT:
            this->select();
            break;
        case KEY_CODE_OPTIONS:
            this->options();
            break;
    }
}

void Context::exit(){
    this->is_active = false;
}