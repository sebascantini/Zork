#include <curses.h>
#include <bits/stdc++.h> 
#include "headers/context.h"
#include "headers/interface.h"
#include "headers/options.h"

const int getInput(){
    timeout(-1);
    int c = getch();
    return (int) c;
}

void initiateScreen(){
    initscr();
}

void deleteScreen(){
    endwin();
}

const int getControl(){
    int input = getInput();
    while(options->getInputCode(input) == -1)
        input = getInput();
    return options->getInputCode(input);
}

void printLine(std::string s){
    printw((s+'\n').c_str());
}

void print(std::vector<std::string> screen){
    clear();

    for(int i = 0; i < screen.size(); ++i)
        printLine(screen[i]);
    std::cout << std::endl;
}