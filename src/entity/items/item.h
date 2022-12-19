#ifndef ITEM_H
#define ITEM_H

#include "../entity.h"

class Item : public Entity{
    public:
        Item(int id);
        char getSymbol() override;
        bool isItem() override;
};

enum ITEM_ID {POTION};

#endif