#ifndef INTERFACE_H
#define INTERFACE_H

#include <curses.h>
#include "context.h"
#include "settings.h"
#include <string>
#include <vector>

class Interface{
    public:
        Interface();
        ~Interface();
        const int getKey();
        void getInput(Context* context);
        void log(std::string msg);
        void printTop(std::vector<std::string> screen);
        void printBot(std::vector<std::string> screen);
    private:
        WINDOW* window_top;
        WINDOW* window_bot;
        Settings settings;
        void print(WINDOW* window, int position_y, int position_x, std::vector<std::string> screen);
        void refreshScreen();
        void refreshWindow(WINDOW* window);
};

void initializeInterface();
void finalizeInterface();

extern Interface* interface;

#endif