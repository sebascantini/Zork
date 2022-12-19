#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character{
    public:
        Player();
        char getSymbol() override;
        std::string show();
};

extern Player* player;

void initializePlayer();
void finalizePlayer();

#endif