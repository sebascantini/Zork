#include "combat.h"

Combat::Combat(std::vector<Character*> enemies){
    this->scheduler = new CombatScheduler(enemies);
    this->screen = new CombatScreen();
    this->screen->show();
    this->begin();
}       

Combat::~Combat(){
    delete(this->scheduler);
    delete(this->screen);
}

void Combat::begin(){
    while(scheduler->combatContinues()){
        (scheduler->next())->turn();
        this->screen->show();
    }
}