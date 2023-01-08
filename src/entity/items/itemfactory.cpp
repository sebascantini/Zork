#include "itemfactory.h"

Item* ItemFactory::create(int item_id){
    return new Item();
}