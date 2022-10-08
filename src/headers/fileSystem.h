#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "location.h"
#include "locationPackage.h"

Location* loadWorld();
LocationPackage* loadLocation(std::string file_name);

#endif