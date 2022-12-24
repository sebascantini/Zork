#include "location.h"
#include "../general/math.h"
#include "../entity/characters/player.h"
#include "../general/settings/paths.h"
#include "../entity/entities.h"
#include <fstream>

#define SUCCESS true;
#define FAILURE false;
#define MAP_FILE_EXTENTION ".location"

Location::Location(std::string file_name){
    this->load(file_name);
}

Location::Location(std::string file_name, std::pair<int, int> starting_player_position){
    this->load(file_name);
    this->movePlayerTo(starting_player_position);
}

Location::~Location(){
    for(int i = 0; i < this->characters.size()-1; ++i)
        delete(this->characters[i]);
    for(auto& entry : this->contents)
        delete(entry.second);
}

void Location::load(std::string file_name){
    int limit, pos_x, pos_y, id;

    std::ifstream file (save_path / map_folder / (file_name + MAP_FILE_EXTENTION));

    //load location name
    file >> this->name;

    //load player
    this->characters.push_back(player);

    //load map
    file >> limit;
    for(int i = 0; i < limit; ++i){
        std::string map_row;
        file >> map_row;
        this->map.push_back(map_row);
    }

    if(file.eof()){
        file.close();
        return;
    }

    // load location accesses
    file >> limit;
    for(int i = 0; i < limit; ++i){
        file >> pos_x >> pos_y;
        this->contents[hash(pos_x, pos_y)] = new Access(i, std::make_pair(pos_x, pos_y));
    }

    if(file.eof()){
        file.close();
        return;
    }

    //add items
    file >> limit;
    for(int i = 0; i < limit; ++i){
        file >> id >> pos_x >> pos_y;
        this->contents[hash(pos_x, pos_y)] = new Item(id);
    }
    
    file.close();
}

const std::string Location::getName(){
    return this->name;
}

const std::vector<std::string> Location::getMap(){
    std::vector<std::string> map_copy = this->map;
    //print contents
    for(auto& entry : this->contents){
        std::pair<int, int> position = unhash(entry.first);
        map_copy[position.first][position.second] = entry.second->getSymbol();
    }
    //print characters
    for(int i = 0; i < this->characters.size(); ++i){
        std::pair<int, int> character_position = this->character_positions[this->characters[i]];
        map_copy[character_position.first][character_position.second] = this->characters[i]->getSymbol();
    }
    return map_copy;
}

void Location::moveUp(){
    this->movePlayer(-1, 0);
}

void Location::moveDown(){
    this->movePlayer(1, 0);
}

void Location::moveLeft(){
    this->movePlayer(0, -1);
}

void Location::moveRight(){
    this->movePlayer(0, 1);
}

void Location::interact(){
    int player_position_hash = hash(this->character_positions[player].first, this->character_positions[player].second);
    if(this->contents.find(player_position_hash) == this->contents.end())
        return;
    if(this->contents[player_position_hash]->isItem())
        contents.erase(this->contents.find(player_position_hash));

}

int Location::getExitID(){
    return this->contents[hash(this->character_positions[player].first, this->character_positions[player].second)]->getID();
}

std::pair<int, int> Location::getEntranceFrom(int origin_id){
    std::pair<int, int> position = {-1, -1};
    for(auto& entry : this->contents)
        if(entry.second->isAccess() && entry.second->getID() == origin_id)
            position = entry.second->getExit();
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
    return FAILURE;
}