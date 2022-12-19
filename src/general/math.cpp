#include <assert.h>
#include <cmath>
#include "math.h"
#include <bsd/stdlib.h>

int hash(int x, int y){
    return pow(2, x) * ((2 * y) + 1);
}

std::pair<int, int> unhash(int i){
    int x = log2(i & (~(i - 1)));
    int y = ((i / pow(2, x)) -1) / 2;
    return std::make_pair(x, y);
}

bool tryEvent(double probability){
    assert(probability >= 0.0 && probability <= 1.0);
    const int resolution = 100000;
    double random_number = arc4random_uniform(resolution);
    random_number /= (double) resolution;
    return random_number <= probability;
}