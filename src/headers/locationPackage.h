#ifndef LOCATIONPACKAGE_H
#define LOCATIONPACKAGE_H

#include <vector>
#include <string>
#include <unordered_map>

class LocationPackage{
    public:
        LocationPackage(std::string location_name, std::vector<std::string> location_map, std::unordered_map<int, int> location_contents, std::vector<std::pair<int, int>> location_entrances);
        const std::string getName();
        const std::vector<std::string> getMap();
        int getExitID();
        std::pair<int, int> getEntranceFrom(int origin_id);
        bool movePlayer(int shift_x, int shift_y);
        bool movePlayerTo(int new_player_position_x, int new_player_position_y);
        bool playerIsOnExit();
    private:
        std::string name;
        std::vector<std::string> map;
        std::pair<int, int> player_position;
        std::unordered_map<int, int> contents;
        std::vector<std::pair<int, int>> entrances;
};

#endif