#include "locationnode.h"

LocationNode::LocationNode(std::string file_name){
    this->file_name = file_name;
}

std::string LocationNode::name(){
    return file_name;
}

void LocationNode::addNearbyLocation(LocationNode* location){
    this->nearby_locations.push_back(location);
}

const std::vector<LocationNode*> LocationNode::getNearbyLocations(){
    return this->nearby_locations;
}
