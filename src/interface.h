#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>

std::string askForInput();

const int askForInt(int max = 10);

void print(std::vector<std::string> screen);

#endif