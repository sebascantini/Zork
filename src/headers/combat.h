#ifndef COMBAT_H
#define COMBAT_H

#include "context.h"
#include "scheduler.h"

class Combat : public Context{
    public:
        Combat(std::vector<Character*> &enemies);
        ~Combat();
        bool isActive() override;
        void next() override;
        void playerTurn();
        void moveUp() override;
        void moveDown() override;
        void select() override;
        void show() override;
    private:
        Scheduler* scheduler;
        std::vector<Character*> characters;
        int enemies;
        void attack();
        void useItem();
        void run();
        std::string selection(int item);
};

#endif