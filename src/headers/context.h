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
        virtual void options() {}
        virtual void playerTurn(){}
    private:
        virtual void show() {}
};

void runContext(Context* context);

#endif