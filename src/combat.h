#ifndef COMBAT_H
#define COMBAT_H

#include <vector>
#include "character.h"

class Combat{
    public:
        Combat(std::vector<Character*> enemies);
        int begin();
    private:
        std::vector<Character*> characters;
};

#endif