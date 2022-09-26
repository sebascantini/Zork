#ifndef LOCATION_H
#define LOCATION_H

#include "context.h"
#include "character.h"
#include "map.h"

class Location : public Context{
    public:
        Location(Map* m);
        bool isActive() override;
        void next() override;
    protected:
        Map* map;
        std::pair<int, int> player_position;
    private:
        std::vector<void (Location::*)()> commands;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void show() override;
        void encounter();
};

#endif