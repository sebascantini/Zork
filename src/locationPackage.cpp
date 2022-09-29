#include <fstream>
#include <math.h>
#include "locationPackage.h"
#include "combat.h"
#include "enemy.h"

#define MAP_FOLDER "files/maps/"
#define FILE_EXTENTION ".map"
#define SUCCESS true;
#define FAILURE false;

LocationPackage::LocationPackage(std::string file_name){
    int limit;
    std::ifstream location_file (MAP_FOLDER + file_name + FILE_EXTENTION);

    location_file >> this->name;
    location_file >> limit;
    for(int i = 0; i < limit; ++i){
        std::string map_row;
        location_file >> map_row;
        this->map.push_back(map_row);
    }
    
    location_file >> limit;
    for(int i = 0; i < limit; ++i){
        int exit_x, exit_y;
        location_file >> exit_x >> exit_y;
        this->contents[hash(exit_x, exit_y)] = i;
    }

    location_file.close();

    player_position = std::make_pair(9, 0);
}

const std::string LocationPackage::getName(){
    return this->name;
}

const std::vector<std::string> LocationPackage::getMap(){
    std::vector<std::string> map_copy = this->map;
    map_copy[player_position.first][player_position.second] = 'p';
    return map_copy;
}

int LocationPackage::hash(int x, int y){
    return pow(2, x) * (2 * y + 1);
}

bool LocationPackage::movePlayerUp(){
    return this->movePlayerTo(this->player_position.first - 1, this->player_position.second);
}

bool LocationPackage::movePlayerDown(){
    return this->movePlayerTo(this->player_position.first + 1, this->player_position.second);
}

bool LocationPackage::movePlayerLeft(){
    return this->movePlayerTo(this->player_position.first, this->player_position.second - 1);
}

bool LocationPackage::movePlayerRight(){
    return this->movePlayerTo(this->player_position.first, this->player_position.second + 1);
}

bool LocationPackage::movePlayerTo(int new_player_position_x, int new_player_position_y){
    if(new_player_position_x < 0 || new_player_position_x >= this->map.size() || new_player_position_y < 0 || new_player_position_y >= this->map[0].size())
        return FAILURE;
    if(this->map[new_player_position_x][new_player_position_y] != '#'){
        player_position = std::make_pair(new_player_position_x, new_player_position_y);
        return SUCCESS;
    }
    
    return FAILURE;
}

bool LocationPackage::playerIsOnExit(){
    int player_position_hash = this->hash(this->player_position.first, this->player_position.second);
    return this->contents.find(player_position_hash) != this->contents.end();
}

void LocationPackage::triggerEncounter(){
    std::vector<Character*> enemies = {new Enemy()};
    runContext(new Combat(enemies));
}