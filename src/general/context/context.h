#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include "menuselector.h"

class Context{
    public:
        void run();
        virtual void next(){}
        virtual void moveUp() {}
        virtual void moveDown() {}
        virtual void moveLeft() {}
        virtual void moveRight() {}
        virtual void select() {}
        virtual void options() {}
        virtual void playerTurn(){}
        virtual void show() {}
    protected:
        MenuSelector selector;
        void exit();
    private:
        bool is_active = true;
};

void runContext(Context* context);

#endif