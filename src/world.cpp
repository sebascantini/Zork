#include <fstream>
#include <sstream>
#include "location.h"
#include "world.h"

#define world_file "files/maps/connectivity.world"

std::vector<Location*> locations;
std::vector<std::string> maps;
int current_location_id;

void loadWorld(){
    std::ifstream connectivity_file (world_file);
    
    int location_id = 0;
    std::string temporary_file_line;
    while(std::getline(connectivity_file, temporary_file_line)){
        std::istringstream file_line (temporary_file_line);
        std::string file_name;
        int adjacent_location_id;
        locations.push_back(new Location());
        file_line >> file_name;
        maps.push_back(file_name);
        while(file_line >> adjacent_location_id)
            locations[location_id]->addNearbyLocation(adjacent_location_id);
        location_id++;
    }
}

void unloadWorld(){
    for(int i = 0; i < locations.size();++i)
        delete(locations[i]);
}

Map* changeLocation(int location_id){
    current_location_id = location_id;
    return new Map(current_location_id);
}

std::pair<Map*, std::pair<int, int>> loadLocation(int location_id){
    Map* map = changeLocation(location_id);
    int arriving_edge = locations[current_location_id]->getEdgeOf(0); // forced
    return std::make_pair(map, map->getEntranceFrom(arriving_edge));
}

std::pair<Map*, std::pair<int, int>> moveLocation(int location_edge){
    int location_id = locations[current_location_id]->getNearbyLocation(location_edge);
    int previous_location_id = current_location_id;
    Map* map = changeLocation(location_id);
    int arriving_edge = locations[current_location_id]->getEdgeOf(previous_location_id);
    return std::make_pair(map, map->getEntranceFrom(arriving_edge));
}