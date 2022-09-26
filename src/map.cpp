#include "map.h"
#include <fstream>

#define MAP_FOLDER "files/maps/"
#define FILE_EXTENTION ".map"

Map::Map(int map_id)
{
    int map_size;
    std::string map_row;
    std::ifstream map_file;

    this->id = map_id;
    map_file.open(MAP_FOLDER + maps[map_id] + FILE_EXTENTION);
    map_file >> map_size;

    for(int i = 0; i < map_size; ++i){
        map_file >> map_row;
        this->map.push_back(map_row);
    }

    while(!map_file.eof()){
        int map_id, exit_x, exit_y;
        map_file >> map_id >> exit_x >> exit_y; 
        this->connections.push_back(std::make_pair(map_id, std::make_pair(exit_x, exit_y)));
    }
}

const int Map::getID(){
    return this->id;
}

const std::vector<std::string> Map::getMap(){
    return this->map;
}

std::pair<int, int> primarySearch(std::vector<std::pair<int, std::pair<int, int>>> &v, int elem){
    for(int i = 0; i < v.size(); ++i)
        if(v[i].first == elem)
            return v[i].second;
    return {};
}

int secondarySearch(std::vector<std::pair<int, std::pair<int, int>>> &v, std::pair<int, int> elem){
    for(int i = 0; i < v.size(); ++i)
        if(v[i].second == elem)
            return v[i].first;
    return -1;
}

const int Map::getNextMapID(std::pair<int, int> position){
    return secondarySearch(this->connections, position);
}

const std::pair<int, int> Map::getEntranceFrom(int previous_location_id){
    return primarySearch(this->connections, previous_location_id);
}

const bool Map::isValid(int row, int column){
    if (row < 0 || row >= this->map.size() || column < 0 || column >= this->map[0].size()) // if out of bounds
        return false;
    
    return this->map[row][column] == '.';
}