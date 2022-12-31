#include "maincontext.h"

void MainContext::setWindows(){
    int window_height,  window_width;
    getmaxyx(stdscr, window_height, window_width);
    int position_x = (window_width - MAIN_WINDOW_WIDTH)/2;
    int position_y = (window_height - MAIN_WINDOW_HEIGHT)/2;
    this->window_top = this->createWindowAt(WINDOW_SEPARATOR - 1, MAIN_WINDOW_WIDTH, position_y, position_x);
    this->window_bot = this->createWindowAt(MAIN_WINDOW_HEIGHT - WINDOW_SEPARATOR, MAIN_WINDOW_WIDTH, position_y + WINDOW_SEPARATOR, position_x);
    wrefresh(window_top);
    wrefresh(window_bot);
}

void MainContext::printTop(std::vector<std::string> screen){
    int window_width, window_height, screen_width_max = 0;
    getmaxyx(this->window_top, window_height, window_width);

    for(int i = 0; i < screen.size(); ++i){
        if(screen[i].size() > screen_width_max)
            screen_width_max = screen[i].size();
    }

    int position_x = (window_width -  screen_width_max)/2;
    int position_y = (window_height - screen.size())/2;

    this->printOnWindow(this->window_top, screen, position_y, position_x);
}

void MainContext::printBot(std::vector<std::string> screen){
    int window_width, window_height;
    getmaxyx(this->window_bot, window_height, window_width);
    int position_y = (window_height - screen.size())/2;
    this->printOnWindow(this->window_bot, screen, position_y, 1);
}