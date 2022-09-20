#include <string>
#include "interface.h"
#include "player.h"
#include "commands.h"
#include "combat.h"

Combat::Combat(std::vector<Character*> enemies){
    commands = {attack, useItem, run, options};
    this->enemies = enemies.size();
    this->characters = enemies;
    this->characters.push_back(player); // player in the back
    this->scheduler = new CombatScheduler(characters);
    this->show();
    this->begin();
}       

Combat::~Combat(){
    delete(this->scheduler);
}

void Combat::begin(){
    while(player->getHealth() > 0 && enemies > 0){ //if (player->getHealth() > 0 && characters.size() == 1) then player is the only one alive
        characters[scheduler->next()]->turn(this);
        this->show();
    }
}

void Combat::environmentRun(){
    this->enemies = 0;
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
        "    " + player->getName(),
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