#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>

class Environment{
    public:
        void playerTurn();
        virtual void environmentRun() {}
    protected:
        std::vector<void(*)(Environment*)> commands;
    private:
        bool isInputInvalid(int Input);
};

#endif