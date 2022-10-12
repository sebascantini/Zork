#include <filesystem>
#include <fstream>
#include "headers/fileSystem.h"
#include <math.h>
#include <sstream>

#define SETTINGS_FOLDER "settings/"
#define SETTINGS_DEFAULT_FOLDER "settings/default/"

#define MAP_FOLDER "shared/maps/"
#define MAP_FILE_EXTENTION ".location"
#define WORLD_FILE "shared/maps/connectivity.world"

namespace fs = std::filesystem;

int hash(int x, int y){
    return pow(2, x) * (2 * y + 1);
}

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
    int key_code, key_id;
    while(file >> key_code >> key_id)
        controls[key_id] = key_code;
    return controls;
}

Location* loadWorld(){
    std::ifstream connectivity_file (WORLD_FILE);
    
    std::string temporary_file_line;
    std::vector<std::istringstream*> location_streams;
    std::vector<Location*> locations;


    while(std::getline(connectivity_file, temporary_file_line)){
        std::istringstream* file_line = new std::istringstream (temporary_file_line);
        location_streams.push_back(file_line);
    }

    connectivity_file.close();

    for(int i = 0; i < location_streams.size(); ++i){
        std::string file_name;
        *location_streams[i] >> file_name;
        locations.push_back(new Location(file_name));
    }

    for(int i = 0; i < locations.size(); ++i){
        int location_index;
        while(*location_streams[i] >> location_index)
            locations[i]->addNearbyLocation(locations[location_index]);
    }

    for(int i = 0; i < location_streams.size(); ++i)
        delete(location_streams[i]);

    locations[0]->load();
    locations[0]->movePlayerTo(9, 1);
    return locations[0];
}

LocationPackage* loadLocation(std::string file_name){
    int limit;
    std::string location_name;
    std::vector<std::string> location_map;
    std::unordered_map<int, int> location_contents;
    std::vector<std::pair<int, int>> location_entrances;

    std::ifstream location_file (MAP_FOLDER + file_name + MAP_FILE_EXTENTION);

    location_file >> location_name;
    location_file >> limit;
    for(int i = 0; i < limit; ++i){
        std::string map_row;
        location_file >> map_row;
        location_map.push_back(map_row);
    }
    
    location_file >> limit;
    for(int i = 0; i < limit; ++i){
        int exit_x, exit_y;
        location_file >> exit_x >> exit_y;
        location_contents[hash(exit_x, exit_y)] = i;
        location_entrances.push_back(std::make_pair(exit_x, exit_y));
    }

    location_file.close();

    return new LocationPackage(location_name, location_map, location_contents, location_entrances);
}

