#include "interface.h"
#include "combat.h"
#include "player.h"

Combat::Combat(std::vector<Character*> enemies){
    this->scheduler = new CombatScheduler(enemies);
    this->show();
    this->begin();
}       

Combat::~Combat(){
    delete(this->scheduler);
}

void Combat::begin(){
    while(scheduler->combatContinues()){
        (scheduler->next())->turn();
        this->show();
    }
}

void Combat::show(){
    print({
        "",
        "COMBAT",
        "",
        "   Enemy Data",
        "",
        "",
        "HP: " + std::to_string(player->getCurrentHealth()),
        "",
        "",
        ""
    });
}