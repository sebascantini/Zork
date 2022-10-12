#ifndef LOCATIONNODE_H
#define LOCATIONNODE_H

#include "locationPackage.h"

class LocationNode{
    public:
        LocationNode(std::string file_name);
        ~LocationNode();
        std::string name();
        void addNearbyLocation(LocationNode* location);
        const std::vector<LocationNode*> getNearbyLocations();
    private:
        std::string file_name;
        std::vector<LocationNode*> nearby_locations;
        LocationPackage* location_package;
};

#endif