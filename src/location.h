#ifndef LOCATION_H
#define LOCATION_H

#include "context.h"
#include "character.h"
#include "map.h"

class Location : public Context{
    public:
        Location(int map_id);
        bool isActive() override;
        void next() override;
    protected:
        Map* map;
        std::pair<int, int> player_position;
    private:
        bool is_active = true;
        std::vector<void (Location::*)()> commands;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void movePlayerTo(int row, int column);
        void exit();
        void changeMap(int next_map_id);
        void loadMap(int previous_map_id, int next_map_id);
        void show() override;
        void triggerEncounter();
};

#endif