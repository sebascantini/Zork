#include "headers/location.h"
#include "headers/fileSystem.h"

#define FAILURE false;

Location::Location(std::string file_name){
    this->file_name = file_name;
}

Location::~Location(){
    this->unload();
}

void Location::addNearbyLocation(Location* location){
    this->nearby_locations.push_back(location);
}

const std::vector<Location*> Location::getNearbyLocations(){
    return this->nearby_locations;
}

void Location::load(){
    this->unload();
    this->location_package = loadLocation(this->file_name);
}

void Location::unload(){
    delete(this->location_package);
}

Location* Location::getNextLocation(){
    return this->nearby_locations[this->location_package->getExitID()];
}

bool Location::movePlayerUp(){
    return this->location_package->movePlayerUp();
}

bool Location::movePlayerDown(){
    return this->location_package->movePlayerDown();
}

bool Location::movePlayerLeft(){
    return this->location_package->movePlayerLeft();
}

bool Location::movePlayerRight(){
    return this->location_package->movePlayerRight();
}

bool Location::playerIsOnExit(){
    return this->location_package->playerIsOnExit();
}

bool Location::movePlayerTo(int new_player_position_x, int new_player_position_y){
    return this->location_package->movePlayerTo(new_player_position_x, new_player_position_y);
}

bool Location::placePlayerFrom(Location* previous_location, int entrance_shift_x, int entrance_shift_y){
    for(int i = 0; i < this->nearby_locations.size(); ++i){
        if(this->nearby_locations[i] == previous_location){
            std::pair<int, int> entrance_position = this->location_package->getEntranceFrom(i);
            this->movePlayerTo(entrance_position.first + entrance_shift_x, entrance_position.second + entrance_shift_y);
        }
    }
    return FAILURE;
}

const std::vector<std::string> Location::getMap(){
    return this->location_package->getMap();
}