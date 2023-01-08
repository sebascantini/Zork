#ifndef CHARACTER_H
#define CHARACTER_H

#include "../entity.h"

class Character : public Entity {
    public:
        Character() {};
        char getSymbol() override;
        bool isCharacter() override;
        void increaseHealth(int amount);
    protected:
        int health = 100;
};

#endif