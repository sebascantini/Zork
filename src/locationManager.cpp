#include "headers/combat.h"
#include "headers/fileSystem.h"
#include "headers/interface.h"
#include "headers/locationManager.h"
#include "headers/player.h"
#include "headers/math.h"

#include "headers/enemy.h" // to remove in further update


LocationManager::LocationManager(){
    initializePlayer(); // shouldn't be here
    this->current_location = loadWorld();
    this->location_data = loadLocation(this->current_location->name());
    this->location_data->movePlayerTo(9, 1); // shouldn't be here
    this->show();
}

LocationManager::~LocationManager(){
    deletePlayer(); // shouldn't be here
    delete(this->current_location);
    delete(this->location_data);
}

bool LocationManager::isActive(){
    return this->is_active;
}

void LocationManager::next(){
    getInput(this);
    this->show();
}

void LocationManager::changeLocation(int entrance_shift_x, int entrance_shift_y){
    //update location
    LocationNode* previous_location = this->current_location;
    this->current_location = previous_location->getNearbyLocations()[this->location_data->getExitID()];
    
    //load location data
    delete(this->location_data);
    this->location_data = loadLocation(this->current_location->name());

    //place player at entrance
    std::vector<LocationNode*> nearby_locations = current_location->getNearbyLocations();
    for(int i = 0; i < nearby_locations.size(); ++i){
        if(nearby_locations[i] == previous_location){
            std::pair<int, int> entrance_position = this->location_data->getEntranceFrom(i);
            this->location_data->movePlayerTo(entrance_position.first + entrance_shift_x, entrance_position.second + entrance_shift_y);
        }
    }
}

void LocationManager::moveUp(){
    this->movePlayer(-1, 0);
}

void LocationManager::moveDown(){
    this->movePlayer(1, 0);
}

void LocationManager::moveLeft(){
    this->movePlayer(0, -1);
}

void LocationManager::moveRight(){
    this->movePlayer(0, 1);
}

void LocationManager::movePlayer(int shift_x, int shift_y){
    if(this->location_data->movePlayer(shift_x, shift_y)){
        if(this->location_data->playerIsOnExit())
            this->changeLocation(shift_x, shift_y);
        else
            this->attemptEncounter();
    }
}

void LocationManager::options(){
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
        "    w. Move Up",
        "    s. Move Down",
        "    a. Move Left",
        "    d. Move Right",
        "    esc. Quit"
        "",
        "",
        " =============================================================================================== ",
        ""
    };
    std::vector<std::string> map_copy = this->location_data->getMap();

    for(int i = 0; i < map_copy.size(); ++i) // insert map
        screen.insert(screen.begin() + i + 4, "       " + map_copy[i]);
    
    print(screen);
}

void LocationManager::attemptEncounter(){
    if(tryEvent(0.05))
        triggerEncounter();
}

void LocationManager::triggerEncounter(){
    std::vector<Character*> enemies = {new Enemy()};
    runContext(new Combat(enemies));
}