#ifndef CHARACTER_H
#define CHARACTER_H

#include "weapon.h"
#include <string>

class Character{
    public:
        ~Character();
        const std::string getName();
        const int getHealth();
        const int getSpeed();
        const int getCurrentHealth();
        virtual void turn() {};

    protected:
        void attack(Character* target);
        void getAttacked(int dmg);
        std::string name;
        int health;
        int defence;
        int strength;
        int speed;
        int current_health;
        Weapon* weapon;

    private:
        const int outputDamage();
        const int inputDamage(const int dmg);
};

#endif