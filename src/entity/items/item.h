#ifndef ITEM_H
#define ITEM_H

#include "../entity.h"

class Item : public Entity{
    public:
        Item () {}
        char getSymbol() override;
        bool isItem() override;
};

#endif