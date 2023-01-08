#ifndef WINDOW_H
#define WINDOW_H

#include <curses.h>
#include <vector>
#include <string>

#define MAX_WINDOW_HEIGHT 99
#define MAX_WINDOW_WIDTH 38

class Window{
    public:
        Window(){}
        Window(int height, int width, int position_y, int position_x);
        void printOnWindow(std::vector<std::string> screen, int position_y, int position_x);
        void getSize(int &width, int &height);
        void refresh();
        void erase();
    protected:
        WINDOW *window;
        void setBorders();
};

#endif