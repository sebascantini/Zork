#ifndef COMBAT_H
#define COMBAT_H

#include <vector>
#include "screen.h"
#include "character.h"

class Combat{
    public:
        Combat(std::vector<Character*> e);
    private:
        std::vector<Character*> characters;
        void battleMessage(std::string m);
        Screen* screen;
        int begin();
};

#endif