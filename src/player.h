#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character{
    public:
        std::string turn() override;
};

extern Player* player;

#endif