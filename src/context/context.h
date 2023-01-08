#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include "menuselector.h"

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
        void log(std::string log_message);
    private:
        bool is_active;
};

#define MAX_WINDOW_HEIGHT 99
#define MAX_WINDOW_WIDTH 38

#define LOG_WINDOW_HEIGHT 20
#define LOG_WINDOW_WIDTH 39

#endif