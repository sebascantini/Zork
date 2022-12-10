#include <filesystem>
#include <fstream>
#include "headers/filesystem.h"
#include "headers/math.h"
#include "headers/access.h"
#include "headers/item.h"
#include <sstream>

#define SETTINGS_FOLDER "settings/"
#define SETTINGS_DEFAULT_FOLDER "settings/default/"

#define MAP_FOLDER "shared/maps/"
#define MAP_FILE_EXTENTION ".location"
#define WORLD_FILE "shared/maps/connectivity.world"

namespace fs = std::filesystem;

std::ifstream loadOptions(std::string file_name){
    std::ifstream file (SETTINGS_FOLDER + file_name);
    if(!file.is_open()){
        fs::copy(SETTINGS_DEFAULT_FOLDER + file_name, SETTINGS_FOLDER + file_name);
        file.open(SETTINGS_FOLDER + file_name);
    }
    return file;
}

std::unordered_map<int, int> loadControls(){
    std::ifstream file = loadOptions("controls");
    std::unordered_map<int, int> controls;
    int key_code, key_id = 0;
    while(file >> key_code){
        controls[key_code] = key_id;
        key_id++;
    }
    return controls;
}

LocationNode* loadWorld(){
    std::ifstream connectivity_file (WORLD_FILE);
    
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
        
    return locations[0];
}

Location* loadLocation(std::string file_name){
    int limit, pos_x, pos_y, id;
    std::string location_name;
    std::vector<std::string> location_map;
    std::unordered_map<int, Object*> location_contents;
    std::vector<std::pair<int, int>> location_entrances;

    std::ifstream location_file (MAP_FOLDER + file_name + MAP_FILE_EXTENTION);

    //load map
    location_file >> location_name;
    location_file >> limit;
    for(int i = 0; i < limit; ++i){
        std::string map_row;
        location_file >> map_row;
        location_map.push_back(map_row);
    }

    // load location accesses
    location_file >> limit;
    for(int i = 0; i < limit; ++i){
        location_file >> pos_x >> pos_y;
        location_contents[hash(pos_x, pos_y)] = new Access(i, std::make_pair(pos_x, pos_y));
    }

    //add items
    location_file >> limit;
    for(int i = 0; i < limit; ++i){
        location_file >> id >> pos_x >> pos_y;
        location_contents[hash(pos_x, pos_y)] = new Item(id);
    }

    location_file.close();
    return new Location(location_name, location_map, location_contents);
}

