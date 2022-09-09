#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
    public:
        Character();
        const int actualHealth();
        virtual void turn() {}

    protected:
        void attack(Character* target, int dmg);
        void getAttacked(int dmg);
        void updateStats();

    private:
        int base_hp;
        int base_def;
        int base_atk;
        int final_hp;
        int final_def;
        int final_atk;
        int hp;
        const int outputDamage(const int dmg);
        const int inputDamage(const int dmg);
};

#endif