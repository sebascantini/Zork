#ifndef COMBAT_H
#define COMBAT_H

#include "combatScreen.h"
#include "combatScheduler.h"

class Combat{
    public:
        Combat(std::vector<Character*> enemies);
        ~Combat();
    private:
        CombatScreen* screen;
        CombatScheduler* scheduler;
        void begin();
};

#endif