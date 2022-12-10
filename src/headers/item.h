#ifndef ITEM_H
#define ITEM_H

#include "object.h"

class Item : public Object{
    public:
        Item(int id);
        bool isItem() override;
};

enum ITEM_ID {POTION};

#endif