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
        void playerTurn() override;
    private:
        Scheduler* scheduler;
        std::vector<void (Combat::*)()> commands;
        std::vector<Character*> characters;
        int enemies;
        void attack();
        void useItem();
        void run();
        void options();
        void show() override;
};

#endif