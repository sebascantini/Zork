#ifndef COMBATSCHEDULER_H
#define COMBATSCHEDULER_H

#include <vector>
#include "character.h"

class CombatScheduler{
    public:
        CombatScheduler(std::vector<Character*> enemies);
        Character* next();
        bool combatContinues();
    private:
        std::vector<std::vector<int>> scheduling_table;
        std::vector<Character*> characters;
};

#endif