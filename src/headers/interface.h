#ifndef INTERFACE_H
#define INTERFACE_H

#include "context.h"
#include <string>
#include <vector>

const int getKey();

void getInput(Context* context);

void initializeInterface();
void finalizeInterface();

void print(std::vector<std::string> screen);

#endif