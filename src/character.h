#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "environment.h"
#include "weapon.h"

class Character{
    public:
        ~Character();
        const std::string getName();
        const int getHealth();
        const int getSpeed();
        const int getCurrentHealth();
        const bool isAlive();
        void heal(int amount);
        void attack(Character* target);
        virtual void turn(Environment* environment) {};

    protected:
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