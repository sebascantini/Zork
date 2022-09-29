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
        void validateLocation();
        void changeLocation();
};

#endif