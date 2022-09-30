#ifndef LOCATIONPACKAGE_H
#define LOCATIONPACKAGE_H

#include <vector>
#include <string>
#include <unordered_map>

class LocationPackage{
    public:
        LocationPackage(std::string file_name);
        const std::string getName();
        const std::vector<std::string> getMap();
        int getExitID();
        std::pair<int, int> getEntranceFrom(int origin_id);
        bool movePlayerUp();
        bool movePlayerDown();
        bool movePlayerLeft();
        bool movePlayerRight();
        bool movePlayerTo(int new_player_position_x, int new_player_position_y);
        bool playerIsOnExit();
    private:
        std::string name;
        std::vector<std::string> map;
        std::pair<int, int> player_position;
        std::unordered_map<int, int> contents;
        std::vector<std::pair<int, int>> entrances;
        int hash(int x, int y);
        void triggerEncounter();
};

#endif