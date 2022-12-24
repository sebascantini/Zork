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
    private:
        bool is_active;
};

#endif