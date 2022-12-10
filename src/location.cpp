#include "headers/location.h"
#include "headers/interface.h"
#include "headers/math.h"
#include "headers/player.h"

#define SUCCESS true;
#define FAILURE false;

Location::Location(std::string location_name, std::vector<std::string> location_map, std::unordered_map<int, Object*> location_contents){
    this->name = location_name;
    this->map = location_map;
    this->contents = location_contents;
    this->characters = std::vector<Character *>(0);
    this->characters.push_back(player);
}

Location::~Location(){
    for(int i = 0; i < this->characters.size()-1; ++i)
        delete(this->characters[i]);
}

const std::string Location::getName(){
    return this->name;
}

const std::vector<std::string> Location::getMap(){
    std::vector<std::string> map_copy = this->map;
    for(auto& entry : contents){
        std::pair<int, int> position = unhash(entry.first);
        map_copy[position.first][position.second] = entry.second->get_symbol();
    }
    for(int i = 0; i < this->characters.size(); ++i){
        std::pair<int, int> character_position = this->character_positions[this->characters[i]];
        map_copy[character_position.first][character_position.second] = this->characters[i]->get_symbol();
    }
    return map_copy;
}

int Location::getExitID(){
    return this->contents[hash(this->character_positions[player].first, this->character_positions[player].second)]->get_id();
}

std::pair<int, int> Location::getEntranceFrom(int origin_id){
    std::pair<int, int> position = {-1, -1};
    for(auto& entry : contents)
        if(entry.second->isAccess() && entry.second->get_id() == origin_id)
            position = entry.second->get_exit();
    return position;
}

bool Location::movePlayer(int shift_x, int shift_y){
    return this->movePlayerTo(std::make_pair(this->character_positions[player].first + shift_x, this->character_positions[player].second + shift_y));
}

bool Location::movePlayerTo(std::pair<int, int> new_player_position){
    if(!this->isPositionInRangeAndEmpty(new_player_position))
        return FAILURE;
    if(this->map[new_player_position.first][new_player_position.second] != '#'){
        this->character_positions[player] = std::make_pair(new_player_position.first, new_player_position.second);
        return SUCCESS;
    }
    return FAILURE;
}

bool Location::isPositionInRangeAndEmpty(std::pair<int, int> position){
    if(position.first < 0 || position.first >= this->map.size() || position.second < 0 || position.second >= this->map[0].size()) // if not in range
        return false;
    
    bool isEmpty = this->map[position.first][position.second] != '#';
    for(int i = 0; i < this->characters.size()-1; ++i)
        isEmpty &= this->character_positions[this->characters[i]] != position;
    return isEmpty;
}

bool Location::playerIsOnExit(){
    int player_position_hash = hash(this->character_positions[player].first, this->character_positions[player].second);
    if(this->contents.find(player_position_hash) != this->contents.end())
        return contents[player_position_hash]->isAccess();
    return false;
}