#include "item.h"
#include "../../settings/symbols.h"

Item::Item(int id){
    this->id = id;
}

char Item::getSymbol(){
    return ITEM_SYMBOL;
}

bool Item::isItem(){
    return true;
}