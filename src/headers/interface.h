#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>
#include <unistd.h>

std::string askForInput();

const int askForInt(int max = __INT_MAX__);

void print(std::vector<std::string> screen);

#endif