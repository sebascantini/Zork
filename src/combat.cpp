#include "interface.h"
#include "player.h"
#include "commands.h"
#include "combat.h"

Combat::Combat(std::vector<Character*> &enemies){
    commands = {attack, useItem, run, options};
    this->enemies = enemies.size();
    this->characters = enemies;
    this->characters.push_back(player); // player in the back
    this->scheduler = new CombatScheduler(this->characters);
    this->show();
}       

Combat::~Combat(){
    delete(this->scheduler);
}

bool Combat::isActive(){
    return (player->isAlive() && this->enemies > 0);
}

void Combat::next(){
    characters[scheduler->next()]->turn(this);
    this->show();
}

void Combat::environmentAttack(){
    player->attack(this->characters[0]);
    this->enemies -= !(this->characters[0]->isAlive()); // if enemy is dead -1 enemies
}

void Combat::environmentUseItem(){
    player->heal(50);
}

void Combat::environmentRun(){
    this->enemies = 0;
}

void Combat::environmentOptions(){

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