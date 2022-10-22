#include <bits/stdc++.h> 
#include <curses.h>
#include <ostream>
#include "headers/interface.h"
#include "headers/settings.h"

#define SCREEN_HEIGHT 38
#define SCREEN_WIDTH 99

Interface* interface;

Interface::Interface(){
    initscr();
    keypad(stdscr, TRUE);
}

Interface::~Interface(){
    endwin();
}

const int Interface::getKey(){
    return (int) getch();
}

void Interface::getInput(Context* context){
    int input;
    do{
        input = getKey();
        context->show();
    }while(settings.getInputCode(input) == -1);
    switch(settings.getInputCode(input)){
        case KEY_CODE_UP:
            context->moveUp();
            break;
        case KEY_CODE_DOWN:
            context->moveDown();
            break;
        case KEY_CODE_LEFT:
            context->moveLeft();
            break;
        case KEY_CODE_RIGHT:
            context->moveRight();
            break;
        case KEY_CODE_SELECT:
            context->select();
            break;
        case KEY_CODE_OPTIONS:
            context->options();
            break;
    }
}

void Interface::printLine(std::string s){
    wprintw(stdscr, (s+'\n').c_str());
}

void Interface::print(std::vector<std::string> screen){
    clear();

    for(int i = 0; i < screen.size(); ++i)
        this->printLine(screen[i]);
    std::cout << std::endl;
}

void initializeInterface(){
    interface = new Interface();
}

void finalizeInterface(){
    delete(interface);
}