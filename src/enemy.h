#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy: public Character{
    public:
        Enemy();
        void turn(Environment* environment) override;
};

#endif