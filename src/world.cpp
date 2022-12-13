#include "headers/character.h"
#include "headers/interface.h"
#include "headers/world.h"
#include "headers/math.h"
#include "headers/player.h"


World::World(LocationNode* current_location){
    initializePlayer();
    this->selector = -1;
    this->current_location = current_location;
    this->location = new Location(this->current_location->name(), std::make_pair(9, 1));
    this->show();
}

World::~World(){
    delete(this->current_location);
    delete(this->location);
    finalizePlayer();
}

void World::next(){
    interface->getInput(this);
}

void World::changeLocation(int entrance_shift_x, int entrance_shift_y){

    //update location
    LocationNode* previous_location = this->current_location;
    this->current_location = previous_location->getNearbyLocations()[this->location->getExitID()];
    
    //load location data
    delete(this->location);
    this->location = new Location(this->current_location->name());

    //place player at entrance
    std::vector<LocationNode*> nearby_locations = current_location->getNearbyLocations();
    for(int i = 0; i < nearby_locations.size(); ++i){
        if(nearby_locations[i] == previous_location){
            std::pair<int, int> entrance_position = this->location->getEntranceFrom(i);
            this->location->movePlayerTo(std::make_pair(entrance_position.first + entrance_shift_x, entrance_position.second + entrance_shift_y));
        }
    }
}

void World::movePlayer(int shift_x, int shift_y){
    if(this->location->movePlayer(shift_x, shift_y))
        if(this->location->playerIsOnExit())
            this->changeLocation(shift_x, shift_y);
}

void World::select(){
    switch(this->selector){
        case -1:
            this->location->interact();
            break;
        case 0:
            this->inventory();
            break;
        case 1:
            this->settings();
            break;
        case 2:
            this->exit();
            break;
    }
}

void World::inventory(){}

void World::settings(){}

void World::show(){
    int i = 0;
    interface->printTop(this->location->getMap());
    interface->printBot({
        player->show(),
        selection(i++) + " Inventory (coming soon)",
        selection(i++) + " Settings (coming soon)",
        selection(i++) + " Quit"
    });
}