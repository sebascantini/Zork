#include "headers/combat.h"
#include "headers/interface.h"
#include "headers/player.h"

bool selected;

Combat::Combat(std::vector<Character*> &enemies){
    this->selector = -1;
    this->location = new Location("battlefield", {"...............", "...............", "...............", "...............", "..............."}, {}, {});
    this->location->movePlayerTo(1, 1);
    this->enemies = enemies.size();
    this->characters = enemies;
    this->characters.push_back(player); // player in the back
    this->scheduler = new Scheduler(this->characters);
    this->show();
}       

Combat::~Combat(){
    delete(this->scheduler);
}

void Combat::next(){
    this->characters[this->scheduler->next()]->turn(this);
    this->show();
    if(!(player->isAlive() && this->enemies > 0))
        this->exit();
}

void Combat::playerTurn(){
    selected = false;
    while(!selected)
        interface->getInput(this);
}

void Combat::movePlayer(int shift_x, int shift_y){
    this->location->movePlayer(shift_x, shift_y);
}

void Combat::select(){
    selected = true;
    switch(this->selector){
        case 0:
            this->attack();
            break;
        case 1:
            this->useItem();
            break;
        case 2:
            this->escape();
            break;
    }
}

void Combat::attack(){
    player->attack(this->characters[0]);
    this->enemies -= !(this->characters[0]->isAlive()); // if enemy is dead -1 enemies
}

void Combat::useItem(){
    player->heal(50);
}

void Combat::escape(){
    this->exit();
}

void Combat::show(){
    int i = 0;
    interface->printTop(location->getMap());
    interface->printBot({
        player->show(),
        selection(i++) + " Attack (20 dmg)",
        selection(i++) + " Heal (+50 hp)",
        selection(i++) + " Run (exit battle)"
    });
}