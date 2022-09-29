#include "interface.h"
#include "world.h"

World::World(){
    this->commands = {&World::moveUp, &World::moveDown, &World::moveLeft, &World::moveRight, &World::exit};
    this->location_manager = new LocationManager();
    this->show();
}

World::~World(){
    delete(location_manager);
}

bool World::isActive(){
    return this->is_active;
}

void World::next(){
    int input = askForInt(this->commands.size());
    (this->*this->commands[input - 1])();
    this->show();
}

void World::moveUp(){
    location_manager->movePlayerUp();
}

void World::moveDown(){
    location_manager->movePlayerDown();
}

void World::moveLeft(){
    location_manager->movePlayerLeft();
}

void World::moveRight(){
    location_manager->movePlayerRight();
}

void World::exit(){
    this->is_active = false;
}

void World::show(){
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
    std::vector<std::string> map_copy = location_manager->getMap();

    for(int i = 0; i < map_copy.size(); ++i) // insert map
        screen.insert(screen.begin() + i + 4, "       " + map_copy[i]);
    
    print(screen);
}