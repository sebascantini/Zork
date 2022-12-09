#include "src/headers/math.h"
#include <iostream>

int main(){
    int num1, num2;
    std::cin >> num1 >> num2;
    int hashed = hash(num1, num2);
    std::cout << hashed << std::endl;
    std::pair<int, int> output = unhash(hashed);
    std::cout << output.first << "       " << output.second << std::endl;
    return 0;
}