#include <string>
#include "interface.h"
#include "player.h"
#include "combat.h"

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
        " ========= Combat ============================================================================== ",
        "",
        "",
        "",
        "",
        "",
        "                                          1. Enemy",
        "",
        "",
        "",
        "",
        "",
        " =============================================================================================== ",
        "",
        "",
        "    " + player.name(),
        "    HP: " + std::to_string(player->getCurrentHealth()) + "/" + std::to_string(player->getHealth()),
        "    SP: ",
        "    MP: ",
        "",
        "",
        "    1. Attack",
        "    2. Use Item",
        "    3. Run",
        "    4. Options",
        "",
        "",
        " =============================================================================================== ",
        "",
    });
}