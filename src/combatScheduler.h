#ifndef COMBATSCHEDULER_H
#define COMBATSCHEDULER_H

#include <vector>
#include "character.h"

class CombatScheduler{
    public:
        CombatScheduler(std::vector<Character*> enemies);
        int next();
    private:
        std::vector<std::vector<int>> scheduling_table;
};

#endif