#include "headers/context.h"

void Context::run(){
    while(this->is_active)
        this->next();
}

void Context::exit(){
    this->is_active = !this->is_active;
}

std::string Context::selection(int item){
    return (this->selector == item) ? "->" : "";
}