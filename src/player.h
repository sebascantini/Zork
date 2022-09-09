#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character{
    public:
        void turn() override;
};

extern Player* player;

#endif