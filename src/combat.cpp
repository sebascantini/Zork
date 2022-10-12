#include "headers/combat.h"
#include "headers/interface.h"
#include "headers/player.h"
#include "headers/settings.h"

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
    this->selector = 0;
    selected = false;
    while(!selected){
        getInput(this);
        this->show();
    }
    switch(this->selector){
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
    this->selector = std::max(this->selector - 1, 0);
}

void Combat::moveDown(){
    this->selector = std::min(this->selector + 1, 2);
}

void Combat::select(){
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

std::string Combat::selection(int item){
    return (this->selector == item) ? "->" : "";
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
        "    " + selection(0) + " Attack (20 dmg)",
        "    " + selection(1) + " Heal (+50 hp)",
        "    " + selection(2) + " Run (exit battle)",
        "",
        "",
        " =============================================================================================== ",
        "",
    });
}