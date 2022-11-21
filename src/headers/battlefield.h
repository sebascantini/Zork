#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "location.h"

class Battlefield : public Location{
    public:
        Battlefield(std::vector<Character*> &characters);
    private:
        void setMap();
        void setCharacterPositions();
};

#endif