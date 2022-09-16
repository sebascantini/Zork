#ifndef COMBAT_H
#define COMBAT_H

#include "combatScheduler.h"

class Combat{
    public:
        Combat(std::vector<Character*> enemies);
        ~Combat();
    private:
        CombatScheduler* scheduler;
        void begin();
        void show();
};

#endif