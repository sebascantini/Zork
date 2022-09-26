#ifndef Map_H
#define Map_H

#include <vector>
#include <string>

class Map{
    public:
        Map(int map_id);
        const int getID();
        const std::vector<std::string> getMap();
        const std::pair<int, int> getEntranceFrom(int prev_map_id);
        const int getNextMapID(std::pair<int, int> position);
        const bool isValid(int row, int column);
        const bool isExit(std::pair<int, int> position);
    private:
        int id;
        std::vector<std::string> map;
        std::vector<std::pair<int, std::pair<int, int>>> connections;
};

extern std::vector<std::string> maps;

#endif