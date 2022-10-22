#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>

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
        int selector = 0;
        void exit();
        std::string selection(int item);
    private:
        bool is_active = true;
};

void runContext(Context* context);

#endif