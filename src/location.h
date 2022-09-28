#ifndef LOCATION_H
#define LOCATION_H

#include <vector>

class Location{
    public:
        void addNearbyLocation(int location_id);
        int getNearbyLocation(int edge_id);
        int getEdgeOf(int location_id);
    private:
        std::vector<int> nearby_locations;
};

#endif