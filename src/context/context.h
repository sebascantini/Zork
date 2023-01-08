#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include "menuselector.h"
#include <curses.h>
#include <vector>

class Context{
    public:
        virtual void moveUp() {}
        virtual void moveDown() {}
        virtual void moveLeft() {}
        virtual void moveRight() {}
        virtual void select() {}
        virtual void options() {}
    protected:
        MenuSelector selector;
        void run();
        const int getKey();
        void getInput();
        void exit();
        virtual void show() {}
        WINDOW* createWindowAt(int height, int width, int position_y, int position_x);
        WINDOW* createCenteredWindow(int height, int width);
        void setBorders(WINDOW* window);
        void printOnWindow(WINDOW* window, std::vector<std::string> screen, int position_y, int position_x);
        void log(std::string log_message);
    private:
        bool is_active;
};

#define MAX_WINDOW_HEIGHT 99
#define MAX_WINDOW_WIDTH 38

#define LOG_WINDOW_HEIGHT 20
#define LOG_WINDOW_WIDTH 39

#endif