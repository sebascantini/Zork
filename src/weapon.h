#ifndef WEAPON_H
#define WEAPON_H

class Weapon{
    public:
        Weapon();
        const int damage();
    private:
        int base_damage;
};

#endif