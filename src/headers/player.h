#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character{
    public:
        Player();
        std::string show();
        void turn(Context* context) override;
        char symbol() override {return 'p';}
    private:
        void setName();
};

extern Player* player;

void initializePlayer();
void deletePlayer();

#endif