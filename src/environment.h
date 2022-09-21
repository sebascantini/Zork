#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>

class Environment{
    public:
        void playerTurn();
        virtual void environmentAttack() {}
        virtual void environmentUseItem() {}
        virtual void environmentRun() {}
        virtual void environmentOptions() {}
    protected:
        std::vector<void(*)(Environment*)> commands;
    private:
        bool isInputInvalid(int Input);
};

#endif