#include <bits/stdc++.h> 
#include <curses.h>
#include <ostream>
#include "headers/interface.h"
#include "headers/settings.h"

void initializeInterface(){
    initscr();
    keypad(stdscr, TRUE);
}

void finalizeInterface(){
    endwin();
}

const int getKey(){
    return (int) getch();
}

void getInput(Context* context){
    int input;
    do{
        input = getKey();
        context->show();
    }while(settings->getInputCode(input) == -1);
    switch(settings->getInputCode(input)){
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

void printLine(std::string s){
    wprintw(stdscr, (s+'\n').c_str());
}

void print(std::vector<std::string> screen){
    clear();

    for(int i = 0; i < screen.size(); ++i)
        printLine(screen[i]);
    std::cout << std::endl;
}