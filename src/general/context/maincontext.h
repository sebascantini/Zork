#ifndef MAINCONTEXT_H
#define MAINCONTEXT_H

#include "context.h"

class MainContext : public Context{
    protected:
        void setWindows();
        void printTop(std::vector<std::string> screen);
        void printBot(std::vector<std::string> screen);
        WINDOW* window_top;
        WINDOW* window_bot;
};

#define MAIN_WINDOW_WIDTH 99
#define MAIN_WINDOW_HEIGHT 39
#define WINDOW_SEPARATOR 29

#endif