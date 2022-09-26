#include <cstdlib>
#include "probability.h"

bool chance(int aPercentage){
    return (rand() % 100) < aPercentage;
}