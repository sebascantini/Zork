#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "item.h"

class ItemFactory{
    public:
        Item* create(int item_id);
};

#endif