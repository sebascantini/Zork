#ifndef LOCATION_H
#define LOCATION_H

#include "../entity/characters/character.h"
#include <string>
#include <unordered_map>
#include <vector>

class Location{
    public:
        Location(std::string file_name);
        Location(std::string file_name, std::pair<int, int> starting_player_position);
        ~Location();
        const std::string getName();
        const std::vector<std::string> getMap();
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
        void interact();
        int getExitID();
        std::pair<int, int> getEntranceFrom(int origin_id);
        bool movePlayerTo(std::pair<int, int> new_player_position); // should be private
        bool playerIsOnExit();
    protected:
        std::string name;
        std::vector<std::string> map;
        std::vector<Character*> characters;
        std::unordered_map<int, Entity*> contents;
        std::unordered_map<Character*,std::pair<int, int>> character_positions;
        void load(std::string file_name);
        bool movePlayer(int shift_x, int shift_y);
        bool isPositionInRangeAndEmpty(std::pair<int, int> position);
};

#endif