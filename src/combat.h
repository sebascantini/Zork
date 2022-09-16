#ifndef COMBAT_H
#define COMBAT_H

#include <vector>
#include "combatScreen.h"
#include "character.h"

class Combat{
    public:
        Combat(std::vector<Character*> e);
    private:
        CombatScreen* screen;
};

#endif