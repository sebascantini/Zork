#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "locationnode.h"
#include "location.h"
#include <unordered_map>

std::unordered_map<int, int> loadControls();
LocationNode* loadWorld();
Location* loadLocation(std::string file_name);

#endif