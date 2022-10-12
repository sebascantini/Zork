#ifndef CONTEXT_H
#define CONTEXT_H

class Context{
    public:
        virtual bool isActive(){return false;}
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
        int selector = 0;
};

void runContext(Context* context);

#endif