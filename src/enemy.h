#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy: public Character{
    public:
        std::string turn() override;
};

#endif