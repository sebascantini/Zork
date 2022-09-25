#ifndef Map_H
#define Map_H

#include <vector>
#include <string>

class Map{
    public:
        Map();
        std::pair<int, int> entrance();
        const bool isValid(int row, int column);
        std::vector<std::string> get();
    private:
        std::vector<std::string> map;
        std::pair<int, int> entrance;
};

#endif