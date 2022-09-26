#ifndef CONTEXT_H
#define CONTEXT_H

class Context{
    public:
        virtual bool isActive(){return false;}
        virtual void next(){}
        virtual void playerTurn(){}
    private:
        virtual void show() {}
};

void runContext(Context* context_to_run);

#endif