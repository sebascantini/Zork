#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>

class Environment{
    public:
        virtual bool isActive(){return false;}
        virtual void next(){}

        //commands
        virtual void environmentAttack() {}
        virtual void environmentUseItem() {}
        virtual void environmentRun() {}
        virtual void environmentOptions() {}
        virtual void environmentMoveUp() {}
        virtual void environmentMoveDown() {}
        virtual void environmentMoveLeft() {}
        virtual void environmentMoveRight() {}
    private:
        virtual void show() {}
};

extern Environment* environment;
extern std::vector<void(*)(Environment*)> commands;

#endif