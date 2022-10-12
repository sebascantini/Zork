#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "location.h"
#include "locationPackage.h"
#include <unordered_map>

std::unordered_map<int, int> loadControls();
Location* loadWorld();
LocationPackage* loadLocation(std::string file_name);

#endif