#include "item.h"
#include "../../config/symbols.h"

char Item::getSymbol(){
    return ITEM_SYMBOL;
}

bool Item::isItem(){
    return true;
}