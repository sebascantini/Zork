#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H

#include "context.h"
#include "character.h"
#include "location.h"
#include <vector>

class LocationManager : public Context{
    public:
        LocationManager();
        ~LocationManager();
        bool isActive() override;
        void next() override;
        const std::vector<std::string> getMap();
    private:
        bool is_active = true;
        Location* current_location;
        std::vector<Location*> nearby_locations;
        std::vector<void (LocationManager::*)()> commands;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void load(Location* location);
        void changeLocation(int entrance_shift_x, int entrance_shift_y);
        void exit();
        void show() override;
};
 
#endif