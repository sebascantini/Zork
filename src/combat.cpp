#include "combat.h"
#include "player.h"
#include <algorithm>
#include <random>

Combat::Combat(std::vector<Character*> enemies){
    enemies.push_back(player);
    this->characters = enemies;
    auto rng = std::default_random_engine {};
    shuffle(this->characters.begin(), this->characters.end(), rng);
}

int Combat::begin(){
    while(player->actualHealth() > 0){
        for(int i = 0; i < this->characters.size(); ++i)
            this->characters[i]->turn();
    }
    return 0;
}