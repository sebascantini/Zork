#ifndef COMBATSCHEDULER_H
#define COMBATSCHEDULER_H

#include <vector>
#include "character.h"

class CombatScheduler{
    public:
        CombatScheduler(std::vector<Character*> &characters);
        int next();
    private:
        std::vector<std::vector<int>> scheduling_table;
        std::vector<Character*> *characters_ptr;
};

#endif