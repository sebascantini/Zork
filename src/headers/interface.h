#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>

const int getInput();

const int getControl();

void initiateScreen();
void deleteScreen();

void print(std::vector<std::string> screen);

#endif