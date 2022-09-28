#ifndef WORLD_H
#define WORLD_H

#include "map.h"

void loadWorld();

void unloadWorld();

std::pair<Map*, std::pair<int, int>> loadLocation(int location_id);

std::pair<Map*, std::pair<int, int>> moveLocation(int location_edge);

#endif