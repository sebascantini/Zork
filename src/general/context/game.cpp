#include "../interface.h"
#include "game.h"
#include "../math.h"
#include "../../entity/characters/player.h"
#include "../settings/paths.h"
#include <fstream>
#include <sstream>


Game::Game(){
    initializePlayer();
    this->loadWorld();
    this->selector = MenuSelector(-1, 2);
    this->location = new Location(this->current_location->name(), std::make_pair(9, 1));
    this->show();
    this->run();
}

Game::~Game(){
    delete(this->current_location);
    delete(this->location);
    finalizePlayer();
}

void Game::moveUp(){
    if(this->moving){
        this->location->moveUp();
        this->changeLocation();
    }
    else
        this->selector.decrease();
}

void Game::moveDown(){
    if(this->moving){
        this->location->moveDown();
        this->changeLocation();
    }
    else
        this->selector.increase();
}

void Game::moveLeft(){
    if(this->moving){
        this->location->moveLeft();
        this->changeLocation();
    }
}

void Game::moveRight(){
    if(this->moving){
        this->location->moveRight();
        this->changeLocation();
    }
}

void Game::select(){
    switch(this->selector.getValue()){
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

void Game::options(){
    this->moving = !this->moving;
    this->selector.toggle();
    this->show();
}

void Game::inventory(){}

void Game::settings(){}

void Game::show(){
    int i = 0;
    interface->printTop(this->location->getMap());
    interface->printBot({
        player->show(),
        this->selector.show(i++) + " Inventory (coming soon)",
        this->selector.show(i++) + " Settings (coming soon)",
        this->selector.show(i++) + " Quit"
    });
}

void Game::changeLocation(){
    if(!this->location->playerIsOnExit())
        return;

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
            this->location->movePlayerTo(std::make_pair(entrance_position.first, entrance_position.second));
        }
    }
}

void Game::loadWorld(){
    std::ifstream connectivity_file (save_path / world_file);
    
    std::string temporary_file_line;
    std::vector<std::istringstream*> location_streams;
    std::vector<LocationNode*> locations;


    while(std::getline(connectivity_file, temporary_file_line)){
        std::istringstream* file_line = new std::istringstream (temporary_file_line);
        location_streams.push_back(file_line);
    }

    connectivity_file.close();

    for(int i = 0; i < location_streams.size(); ++i){
        std::string file_name;
        *location_streams[i] >> file_name;
        locations.push_back(new LocationNode(file_name));
    }

    for(int i = 0; i < locations.size(); ++i){
        int location_index;
        while(*location_streams[i] >> location_index)
            locations[i]->addNearbyLocation(locations[location_index]);
    }

    for(int i = 0; i < location_streams.size(); ++i)
        delete(location_streams[i]);
        
    this->current_location = locations[0];
}