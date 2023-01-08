#include "window.h"

Window::Window(int height, int width, int position_y, int position_x){
    int window_height, window_width;
    getmaxyx(stdscr, window_height, window_width);
    this->window = newwin(height, width, position_y, position_x);
    this->setBorders();
    refresh();
}

void Window::printOnWindow(std::vector<std::string> screen, int position_y, int position_x){
    for(int i = 0; i < screen.size(); ++i)
        mvwprintw(this->window, position_y + i, position_x, (screen[i]+'\n').c_str());

    wrefresh(this->window);
}

void Window::getSize(int &width, int &height){
    getmaxyx(this->window, height, width);
}

void Window::refresh(){
    wrefresh(this->window);
}

void Window::erase(){
    werase(this->window);
    this->setBorders();
}

void Window::setBorders(){
    int window_height,  window_width;
    getmaxyx(this->window, window_height, window_width);
    this->printOnWindow({std::string(window_width, '=')}, 0, 0);
    this->printOnWindow({std::string(window_width, '=')}, window_height - 1, 0);
}