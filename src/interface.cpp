#include <bits/stdc++.h> 
#include <curses.h>
#include <ostream>
#include "headers/context.h"
#include "headers/interface.h"
#include "headers/settings.h"

void initializeInterface(){
    initscr();
}

void finalizeInterface(){
    endwin();
}

const int getInput(){
    return (int) getch();
}

const int getControl(){
    int input;
    do
        input = getInput();
    while(settings->getInputCode(input) == -1);
    return settings->getInputCode(input);
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