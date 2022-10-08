#ifndef CONTEXT_H
#define CONTEXT_H

#include "interface.h"
#include "options.h"

class Context{
    public:
        virtual bool isActive(){return false;}
        virtual void next(){}
        virtual void playerTurn(){}
    private:
        virtual void show() {}
};

void runContext(Context* context);

#endif