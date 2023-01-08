#ifndef MAINCONTEXT_H
#define MAINCONTEXT_H

#include "context.h"
#include "../other/window.h"

class MainContext : public Context{
    protected:
        MainContext(){}
        void setWindows();
        void printTop(std::vector<std::string> screen);
        void printBot(std::vector<std::string> screen);
        Window window_top;
        Window window_bot;
};

#define MAIN_WINDOW_WIDTH 99
#define MAIN_WINDOW_HEIGHT 39
#define WINDOW_SEPARATOR 29

#endif