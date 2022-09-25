#ifndef Map_H
#define Map_H

#include <vector>
#include <string>
#include <unordered_map>

class Map{
    public:
        Map(std::string file_name);
        const int getID();
        const std::vector<std::string> getMap();
        const std::pair<int, int> getEntranceFrom(int prev_location_id);
        const bool isValid(int row, int column);
    private:
        int id;
        std::vector<std::string> map;
        std::unordered_map<int, std::pair<int, int>> starting_positions;
};

#endif