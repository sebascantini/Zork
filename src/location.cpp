#include "location.h"

void Location::addNearbyLocation(int location_id){
    this->nearby_locations.push_back(location_id);
}

int Location::getNearbyLocation(int edge_id){
    return this->nearby_locations[edge_id];
}

int Location::getEdgeOf(int location_id){
    for(int i = 0; i < this->nearby_locations.size(); ++i)
        if(this->nearby_locations[i] == location_id)
            return i;
    return -1;
}