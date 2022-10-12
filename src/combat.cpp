#include "headers/combat.h"
#include "headers/interface.h"
#include "headers/player.h"
#include "headers/settings.h"

int selection;
bool selected;

Combat::Combat(std::vector<Character*> &enemies){
    this->enemies = enemies.size();
    this->characters = enemies;
    this->characters.push_back(player); // player in the back
    this->scheduler = new Scheduler(this->characters);
    this->show();
}       

Combat::~Combat(){
    delete(this->scheduler);
}

bool Combat::isActive(){
    return (player->isAlive() && this->enemies > 0);
}

void Combat::next(){
    this->characters[this->scheduler->next()]->turn(this);
    this->show();
}

void Combat::playerTurn(){
    selection = 0;
    selected = false;
    while(!selected){
        getInput(this);
    }
    switch(selection){
        case 0:
            this->attack();
            break;
        case 1:
            this->useItem();
            break;
        case 2:
            this->run();
            break;
    }
}

void Combat::moveUp(){
    selection = std::min(selection - 1, 0);
}

void Combat::moveDown(){
    selection = std::min(selection + 1, 2);
}

void Combat::options(){
    selected = true;
}

void Combat::attack(){
    player->attack(this->characters[0]);
    this->enemies -= !(this->characters[0]->isAlive()); // if enemy is dead -1 enemies
}

void Combat::useItem(){
    player->heal(50);
}

void Combat::run(){
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
        "    1. Attack (20 dmg)",
        "    2. Heal (+50 hp)",
        "    3. Run (exit battle)",
        "    4. Options (does nothing)",
        "",
        "",
        " =============================================================================================== ",
        "",
    });
}