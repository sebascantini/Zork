#ifndef MATH_H
#define MATH_H

#include <utility>

int hash(int x, int y);
std::pair<int, int> unhash(int i);
bool tryEvent(double probability);

#endif