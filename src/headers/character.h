#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "context.h"
#include "weapon.h"

class Character{
    public:
        Character();
        ~Character();
        const std::string getName();
        const int getMaxHealth();
        const int getSpeed();
        const int getCurrentHealth();
        const bool isAlive();
        void heal(const int amount);
        void attack(Character* target);
        virtual void turn(Context* context);
        virtual char symbol() {return 'c';}

    protected:
        void getAttacked(const int damage);
        std::string name;
        int health;
        int defence;
        int strength;
        int speed;
        int current_health;
        Weapon* weapon;

    private:
        const int outputDamage();
        const int inputDamage(const int damage);
};

#endif