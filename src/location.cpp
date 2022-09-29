#include "location.h"

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
    this->location_package = new LocationPackage(this->file_name);
}

void Location::unload(){
    delete(this->location_package);
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

const std::vector<std::string> Location::getMap(){
    return this->location_package->getMap();
}