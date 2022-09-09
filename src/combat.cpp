#include "combat.h"
#include <algorithm>
#include <random>
#include <iostream>

int combat(std::vector<Character*> characters){
    characters.push_back(player);
    auto rng = std::default_random_engine {};
    shuffle(characters.begin(), characters.end(), rng);
    while(true){
        for(int i = 0; i < characters.size(); ++i)
            characters[i]->turn();
    }
    return 0;
}