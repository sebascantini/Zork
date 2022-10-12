#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character{
    public:
        Player();
        void turn(Context* context) override;
    private:
        void setName();
};

extern Player* player;

void initializePlayer();
void deletePlayer();

#endif