#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H

#include "location.h"

class LocationManager{
    public:
        LocationManager();
        ~LocationManager();
        void movePlayerUp();
        void movePlayerDown();
        void movePlayerLeft();
        void movePlayerRight();
        const std::vector<std::string> getMap();
    private:
        Location* current_location;
        std::vector<Location*> nearby_locations;
        void load(Location* location);
        void changeLocation(int entrance_shift_x, int entrance_shift_y);
};

#endif