#include "headers/item.h"
#include "headers/symbols.h"

Item::Item(int id){
    this->id = id;
    this->symbol = ITEM_SYMBOL;
}

bool Item::isItem(){
    return true;
}