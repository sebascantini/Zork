#include "headers/combat.h"
#include "headers/enemy.h"
#include "headers/fileSystem.h"
#include "headers/interface.h"
#include "headers/locationManager.h"
#include "headers/player.h"


LocationManager::LocationManager(){
    initializePlayer();
    this->current_location = loadWorld();
    this->show();
}

LocationManager::~LocationManager(){
    deletePlayer();
    delete(this->current_location);
}

bool LocationManager::isActive(){
    return this->is_active;
}

void LocationManager::next(){
    getInput(this);
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
    triggerEncounter();
}

void LocationManager::moveRight(){
    if(this->current_location->movePlayerRight())
        if(this->current_location->playerIsOnExit())
            this->changeLocation(0, 1);
}

const std::vector<std::string> LocationManager::getMap(){
    return this->current_location->getMap();
}

void LocationManager::options(){
    this->is_active = false;
}

void LocationManager::triggerEncounter(){
    std::vector<Character*> enemies = {new Enemy};
    runContext(new Combat(enemies));
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
    std::vector<std::string> map_copy = this->getMap();

    for(int i = 0; i < map_copy.size(); ++i) // insert map
        screen.insert(screen.begin() + i + 4, "       " + map_copy[i]);
    
    print(screen);
}