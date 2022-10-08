#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character{
    public:
        Player();
        void turn(Context* environment) override;
    private:
        void setName();
};

extern Player* player;

#endif