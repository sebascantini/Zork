#include <bits/stdc++.h>
#include "interface.h"
#include "settings/settings.h"

#define HEIGHT_WINDOW 38
#define HEIGHT_WINDOW_TOP 24
#define HEIGHT_WINDOW_BOT 6
#define HEIGHT_WINDOW_SETTINGS 20
#define WIDTH_WINDOW 99
#define WIDTH_WINDOW_SUB 95
#define WIDTH_WINDOW_SETTINGS 39

#define POSITION_WINDOW_TOP 3
#define POSITION_WINDOW_BOT 30
#define POSITION_WINDOW_OFFSET 2
#define POSITION_BARRIER_OFFSET 1
#define POSITION_BARRIER_1 1
#define POSITION_BARRIER_2 28
#define POSITION_BARRIER_3 37
#define POSITION_WINDOW_SETTINGS_X 30
#define POSITION_WINDOW_SETTINGS_Y 9

Interface* interface;

void sigwinchHandler(int i){
    interface->refreshScreen();
}

Interface::Interface(){
    signal(SIGWINCH, sigwinchHandler);
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    this->window_top = newwin(HEIGHT_WINDOW_TOP, WIDTH_WINDOW_SUB, POSITION_WINDOW_TOP, POSITION_WINDOW_OFFSET);
    this->window_bot = newwin(HEIGHT_WINDOW_BOT, WIDTH_WINDOW_SUB, POSITION_WINDOW_BOT, POSITION_WINDOW_OFFSET);
    std::string barrier (WIDTH_WINDOW - 2, '=');
    mvprintw(POSITION_BARRIER_1, POSITION_BARRIER_OFFSET, barrier.c_str());
    mvprintw(POSITION_BARRIER_2, POSITION_BARRIER_OFFSET, barrier.c_str());
    mvprintw(POSITION_BARRIER_3, POSITION_BARRIER_OFFSET, barrier.c_str());
    refresh();
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
    context->show();
}

void Interface::log(std::string msg){
    WINDOW* log_window = newwin(HEIGHT_WINDOW_SETTINGS, WIDTH_WINDOW_SETTINGS, POSITION_WINDOW_SETTINGS_Y, POSITION_WINDOW_SETTINGS_X);
    int window_width, window_height;
    getmaxyx(log_window, window_height, window_width);
    int position_x = (window_width - msg.size())/2;
    int position_y = window_height/2;
    this->print(log_window, position_y, 1, {msg});
    wrefresh(log_window);
    sleep(3);
    werase(log_window);
    delwin(log_window);
    this->refreshScreen();
}

void Interface::printTop(std::vector<std::string> screen){
    int window_width, window_height, screen_width_max = 0;
    getmaxyx(this->window_top, window_height, window_width);

    for(int i = 0; i < screen.size(); ++i){
        if(screen[i].size() > screen_width_max)
            screen_width_max = screen[i].size();
    }

    int position_x = (window_width -  screen_width_max)/2;
    int position_y = (window_height - screen.size())/2;

    this->print(this->window_top, position_y, position_x, screen);
}

void Interface::printBot(std::vector<std::string> screen){
    int window_width, window_height;
    getmaxyx(this->window_bot, window_height, window_width);
    int position_y = (window_height - screen.size())/2;
    this->print(this->window_bot, position_y, 1, screen);
}

void Interface::print(WINDOW* window, int position_y, int position_x, std::vector<std::string> screen){
    werase(window);
    for(int i = 0; i < screen.size(); ++i)
        mvwprintw(window, position_y + i, position_x, (screen[i]+'\n').c_str());

    wrefresh(window);
}

void Interface::refreshScreen(){
    this->refreshWindow(stdscr);
    this->refreshWindow(this->window_top);
    this->refreshWindow(this->window_bot);
}

void Interface::refreshWindow(WINDOW* window){
    touchwin(window);
    wrefresh(window);
}

void initializeInterface(){
    interface = new Interface();
}

void finalizeInterface(){
    delete(interface);
}