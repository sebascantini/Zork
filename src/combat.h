#ifndef COMBAT_H
#define COMBAT_H

#include "environment.h"
#include "combatScheduler.h"

class Combat : public Environment{
    public:
        Combat(std::vector<Character*> enemies);
        ~Combat();
        void environmentAttack() override;
        void environmentUseItem() override;
        void environmentRun() override;
        void environmentOptions() override;
    private:
        CombatScheduler* scheduler;
        int enemies;
        std::vector<Character*> characters;
        void begin();
        void show();
};

#endif