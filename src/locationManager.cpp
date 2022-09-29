#include <fstream>
#include <sstream>
#include "locationManager.h"
#include "interface.h"

#define world_file "files/maps/connectivity.world"

LocationManager::LocationManager(){
    std::ifstream connectivity_file (world_file);
    
    std::string temporary_file_line;
    std::vector<std::istringstream*> location_streams;
    std::vector<Location*> locations;

    while(std::getline(connectivity_file, temporary_file_line)){
        std::istringstream* file_line = new std::istringstream (temporary_file_line);
        location_streams.push_back(file_line);
    }

    connectivity_file.close();

    for(int i = 0; i < location_streams.size(); ++i){
        std::string file_name;
        *location_streams[i] >> file_name;
        locations.push_back(new Location(file_name));
    }

    for(int i = 0; i < locations.size(); ++i){
        int location_index;
        while(*location_streams[i] >> location_index)
            locations[i]->addNearbyLocation(locations[location_index]);
    }

    for(int i = 0; i < location_streams.size(); ++i)
        delete(location_streams[i]);

    this->current_location = locations[0];
    this->current_location->load();
}

LocationManager::~LocationManager(){
    delete(this->current_location);
}

void LocationManager::changeLocation(){
    print({"lexicon"});
    sleep(1);
}

void LocationManager::validateLocation(){
    if(this->current_location->playerIsOnExit())
        this->changeLocation();
}

void LocationManager::movePlayerUp(){
    if(this->current_location->movePlayerUp())
        this->validateLocation();
}

void LocationManager::movePlayerDown(){
    if(this->current_location->movePlayerDown())
        this->validateLocation();
}

void LocationManager::movePlayerLeft(){
    if(this->current_location->movePlayerLeft())
        this->validateLocation();
}

void LocationManager::movePlayerRight(){
    if(this->current_location->movePlayerRight())
        this->validateLocation();
}

const std::vector<std::string> LocationManager::getMap(){
    return this->current_location->getMap();
}