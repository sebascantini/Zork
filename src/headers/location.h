#ifndef LOCATION_H
#define LOCATION_H

#include "character.h"
#include <string>
#include <unordered_map>
#include <vector>

class Location{
    public:
        Location(){}
        Location(std::string location_name, std::vector<std::string> location_map, std::unordered_map<int, int> location_contents, std::vector<std::pair<int, int>> location_entrances);
        ~Location();
        const std::string getName();
        const std::vector<std::string> getMap();
        int getExitID();
        std::pair<int, int> getEntranceFrom(int origin_id);
        bool movePlayer(int shift_x, int shift_y);
        bool movePlayerTo(std::pair<int, int> new_player_position);
        bool playerIsOnExit();
    protected:
        std::string name;
        std::vector<std::string> map;
        std::vector<Character*> *characters;
        std::unordered_map<int, int> contents;
        std::vector<std::pair<int, int>> entrances;
        std::unordered_map<Character*,std::pair<int, int>> character_positions;
        bool isPositionInRangeAndEmpty(std::pair<int, int> position);
};

#endif