#ifndef Entity_H
#define Entity_H

#include <string>

class Entity{
    public:
        const int getID();
        const std::string getName();
        virtual char getSymbol();
        virtual std::pair<int, int> getExit();
        virtual bool isAccess();
        virtual bool isItem();
        virtual bool isCharacter();
    protected:
        std::string name;
        int id;
};

#endif