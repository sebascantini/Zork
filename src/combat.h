#ifndef COMBAT_H
#define COMBAT_H

#include "environment.h"
#include "combatScheduler.h"

class Combat : public Environment{
    public:
        Combat(std::vector<Character*> &enemies);
        ~Combat();
        bool isActive() override;
        void next() override;
        void environmentAttack() override;
        void environmentUseItem() override;
        void environmentRun() override;
        void environmentOptions() override;
    private:
        CombatScheduler* scheduler;
        std::vector<Character*> characters;
        int enemies;
        void show() override;
};

#endif