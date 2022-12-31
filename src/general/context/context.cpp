#include "context.h"
#include "../settings/settings.h"
#include <bits/stdc++.h>

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

WINDOW* Context::createWindowAt(int height, int width, int position_y, int position_x){
    WINDOW* output = newwin(height, width, position_y, position_x);
    this->setBorders(output);
    refresh();
    return output;
}

WINDOW* Context::createCenteredWindow(int height, int width){
    int window_height,  window_width;
    getmaxyx(stdscr, window_height, window_width);
    int position_x = (window_width - width)/2;
    int position_y = (window_height - height)/2;
    return this->createWindowAt(height, width, position_y, position_x);
}

void Context::setBorders(WINDOW* window){
    int window_height,  window_width;
    getmaxyx(window, window_height, window_width);
    this->printOnWindow(window, {std::string(window_width, '=')}, 0, 0);
    this->printOnWindow(window, {std::string(window_width, '=')}, window_height - 1, 0);
}

void Context::printOnWindow(WINDOW* window, std::vector<std::string> screen, int position_y, int position_x){
    for(int i = 0; i < screen.size(); ++i)
        mvwprintw(window, position_y + i, position_x, (screen[i]+'\n').c_str());

    wrefresh(window);
}

void Context::log(std::string log_message){
    WINDOW* log_window = this->createCenteredWindow(LOG_WINDOW_HEIGHT, LOG_WINDOW_WIDTH);
    int window_width, window_height;
    getmaxyx(log_window, window_height, window_width);
    int position_x = (window_width - log_message.size())/2;
    int position_y = window_height/2;
    this->printOnWindow(log_window, {log_message}, position_y, 1);
    wrefresh(log_window);
    sleep(3);
    werase(log_window);
    delwin(log_window);
}