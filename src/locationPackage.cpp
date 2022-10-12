#include "headers/combat.h"
#include "headers/enemy.h"
#include "headers/locationPackage.h"
#include "headers/math.h"

#define MAP_FOLDER "shared/maps/"
#define FILE_EXTENTION ".location"
#define SUCCESS true;
#define FAILURE false;

LocationPackage::LocationPackage(std::string location_name, std::vector<std::string> location_map, std::unordered_map<int, int> location_contents, std::vector<std::pair<int, int>> location_entrances){
    this->name = location_name;
    this->map = location_map;
    this->contents = location_contents;
    this->entrances = location_entrances;
}

const std::string LocationPackage::getName(){
    return this->name;
}

const std::vector<std::string> LocationPackage::getMap(){
    std::vector<std::string> map_copy = this->map;
    map_copy[player_position.first][player_position.second] = 'p';
    return map_copy;
}

int LocationPackage::getExitID(){
    return this->contents[hash(this->player_position.first, this->player_position.second)];
}

std::pair<int, int> LocationPackage::getEntranceFrom(int origin_id){
    return this->entrances[origin_id];
}

bool LocationPackage::movePlayer(int shift_x, int shift_y){
    return this->movePlayerTo(this->player_position.first + shift_x, this->player_position.second + shift_y);
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
    int player_position_hash = hash(this->player_position.first, this->player_position.second);
    return this->contents.find(player_position_hash) != this->contents.end();
}