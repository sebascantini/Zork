#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
    public:
        Character();
        const int actualHealth();
        virtual int turn() {return 1;}
    private:
        int max_health;
        int defence;
        int attack;
        int health;
};

class Enemy: public Character{
    public:
        int turn() override;
};

class Player: public Character{
    public:
        int turn() override;
};

extern Player* player;

#endif