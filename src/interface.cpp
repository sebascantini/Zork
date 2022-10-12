#include <bits/stdc++.h> 
#include <curses.h>
#include <ostream>
#include <signal.h>
#include "headers/context.h"
#include "headers/interface.h"
#include "headers/options.h"

const int getInput(){
    timeout(-1);
    int c = getch();
    return (int) c;
}

const int getControl(){
    int input = getInput();
    while(options->getInputCode(input) == -1)
        input = getInput();
    return options->getInputCode(input);
}

void initializeInterface(){
    initscr();
}

void finalizeInterface(){
    endwin();
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