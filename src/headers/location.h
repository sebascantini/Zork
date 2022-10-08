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
        Location* getNextLocation();
        bool movePlayerUp();
        bool movePlayerDown();
        bool movePlayerLeft();
        bool movePlayerRight();
        bool movePlayerTo(int new_player_position_x, int new_player_position_y);
        bool placePlayerFrom(Location* previous_location, int entrance_shift_x, int entrance_shift_y);
        bool playerIsOnExit();
        const std::vector<std::string> getMap();
    private:
        std::string file_name;
        std::vector<Location*> nearby_locations;
        LocationPackage* location_package;
};

#endif