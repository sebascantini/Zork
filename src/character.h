#ifndef CHARACTER_H
#define CHARACTER_H

#include "weapon.h"

class Character{
    public:
        Character();
        ~Character();
        const int getCurrentHealth();
        const int getSpeed();
        virtual void turn() {};

    protected:
        void attack(Character* target);
        void getAttacked(int dmg);
        Weapon* weapon;

    private:
        int health;
        int defence;
        int strength;
        int speed;
        int current_health;
        const int outputDamage();
        const int inputDamage(const int dmg);
};

#endif