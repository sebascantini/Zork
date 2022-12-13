#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character{
    public:
        Player();
        std::string show();
};

extern Player* player;

void initializePlayer();
void finalizePlayer();

#endif