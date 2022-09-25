#include "map.h"
#include <fstream>

#define MAP_FOLDER "files/maps/"
#define FILE_EXTENTION ".map"

Map::Map(std::string file_name)
{
    int map_size;
    std::string map_row;
    std::ifstream map_file;

    map_file.open(MAP_FOLDER + file_name + FILE_EXTENTION);
    map_file >> this->id;
    map_file >> map_size;

    for(int i = 0; i < map_size; ++i){
        map_file >> map_row;
        this->map.push_back(map_row);
    }

    while(!map_file.eof()){
        int map_id, exit_x, exit_y;
        map_file >> map_id >> exit_x >> exit_y; 
        this->starting_positions[map_id] = std::make_pair(exit_x, exit_y);
    }
}

const int Map::getID(){
    return this->id;
}

const std::vector<std::string> Map::getMap(){
    return this->map;
}

const std::pair<int, int> Map::getEntranceFrom(int previous_location_id){
    return this->starting_positions[previous_location_id];
}

const bool Map::isValid(int row, int column){
    return this->map[row][column] == '#';
}