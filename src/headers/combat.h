#ifndef COMBAT_H
#define COMBAT_H

#include "context.h"
#include "scheduler.h"

class Combat : public Context{
    public:
        Combat(std::vector<Character*> &enemies);
        ~Combat();
        void playerTurn() override;
    private:
        Scheduler* scheduler;
        std::vector<Character*> characters;
        int enemies;
        void next() override;
        void moveUp() override;
        void moveDown() override;
        void select() override;
        void show() override;
        void attack();
        void useItem();
        void escape();
};

#endif