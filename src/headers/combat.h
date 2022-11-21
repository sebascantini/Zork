#ifndef COMBAT_H
#define COMBAT_H

#include "game.h"
#include "scheduler.h"

class Combat : public Game{
    public:
        Combat(std::vector<Character*> &enemies);
        ~Combat();
        void playerTurn() override;
    private:
        Scheduler* scheduler;
        std::vector<Character*> characters;
        void next() override;
        void select() override;
        void movePlayer(int shift_x, int shift_y) override;
        void show() override;
        void attack();
        void useItem();
        void escape();
};

#endif