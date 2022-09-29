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
        bool movePlayerUp();
        bool movePlayerDown();
        bool movePlayerLeft();
        bool movePlayerRight();
        bool playerIsOnExit();
    private:
        std::string name;
        std::vector<std::string> map;
        std::pair<int, int> player_position;
        std::unordered_map<int, int> contents;
        int hash(int x, int y);
        bool movePlayerTo(int new_player_position_x, int new_player_position_y);
        void triggerEncounter();
};

#endif