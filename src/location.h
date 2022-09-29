#ifndef LOCATION_H
#define LOCATION_H

#include "locationPackage.h"

class Location{
    public:
        Location(std::string file_name);
        ~Location();
        void addNearbyLocation(Location* location);
        const std::vector<Location*> getNearbyLocations();
        void load();
        void unload();
        bool movePlayerUp();
        bool movePlayerDown();
        bool movePlayerLeft();
        bool movePlayerRight();
        bool playerIsOnExit();
        const std::vector<std::string> getMap();
    private:
        std::string file_name;
        std::vector<Location*> nearby_locations;
        LocationPackage* location_package;
};

#endif