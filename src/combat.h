#ifndef COMBAT_H
#define COMBAT_H

#include "environment.h"
#include "combatScheduler.h"

class Combat : public Environment{
    public:
        Combat(std::vector<Character*> enemies);
        ~Combat();
    private:
        CombatScheduler* scheduler;
        void begin();
        void show();
};

#endif