#include <fstream>
#include <sstream>
#include "headers/interface.h"
#include "headers/locationManager.h"

#define world_file "shared/maps/connectivity.world"

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

    this->load(locations[0]);
    this->current_location->movePlayerTo(9, 1);

    this->commands = {&LocationManager::moveUp, &LocationManager::moveDown, &LocationManager::moveLeft, &LocationManager::moveRight, &LocationManager::exit};
    this->show();
}

LocationManager::~LocationManager(){
    delete(this->current_location);
}

bool LocationManager::isActive(){
    return this->is_active;
}

void LocationManager::next(){
    int input = askForInt(this->commands.size());
    (this->*this->commands[input - 1])();
    this->show();
}

void LocationManager::load(Location* location){
    this->current_location = location;
    this->nearby_locations = this->current_location->getNearbyLocations();
    this->current_location->load();
}

void LocationManager::changeLocation(int entrance_shift_x, int entrance_shift_y){
    Location* previous_location = current_location;
    Location* next_location = previous_location->getNextLocation();
    this->load(next_location);
    this->current_location->placePlayerFrom(previous_location, entrance_shift_x, entrance_shift_y);
}

void LocationManager::moveUp(){
    if(this->current_location->movePlayerUp())
        if(this->current_location->playerIsOnExit())
            this->changeLocation(-1, 0);
}

void LocationManager::moveDown(){
    if(this->current_location->movePlayerDown())
        if(this->current_location->playerIsOnExit())
            this->changeLocation(1, 0);
}

void LocationManager::moveLeft(){
    if(this->current_location->movePlayerLeft())
        if(this->current_location->playerIsOnExit())
            this->changeLocation(0, -1);
}

void LocationManager::moveRight(){
    if(this->current_location->movePlayerRight())
        if(this->current_location->playerIsOnExit())
            this->changeLocation(0, 1);
}

const std::vector<std::string> LocationManager::getMap(){
    return this->current_location->getMap();
}

void LocationManager::exit(){
    this->is_active = false;
}

void LocationManager::show(){
    std::vector<std::string> screen{"",
        " ========= World =============================================================================== ",
        "",
        "",
        "",
        "",
        " =============================================================================================== ",
        "",
        "",
        "    1. Move Up",
        "    2. Move Down",
        "    3. Move Left",
        "    4. Move Right",
        "    5. Quit"
        "",
        "",
        " =============================================================================================== ",
        ""}
    ;
    std::vector<std::string> map_copy = this->getMap();

    for(int i = 0; i < map_copy.size(); ++i) // insert map
        screen.insert(screen.begin() + i + 4, "       " + map_copy[i]);
    
    print(screen);
}