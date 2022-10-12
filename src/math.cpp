#include "headers/math.h"
#include <cmath>

int hash(int x, int y){
    return pow(2, x) * (2 * y + 1);
}