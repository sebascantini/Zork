#include "combat.h"
#include "player.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>

Combat::Combat(std::vector<Character*> e){
    this->characters = e;
    this->characters.push_back(player);
    screen = new Screen("Combat", {"1.Fight", "2.Use Item", "3.Run"});
    screen->lines = {"HP: " + std::to_string(player->actualHealth()), ""};
    screen->printScreen();
    this->begin();
    
}

int Combat::begin(){
    while(player->actualHealth() > 0 && characters.size() != 1){
        for(int i = 0; i < this->characters.size(); ++i){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            this->characters[i]->turn();
            std::string message = "turn passed";
            screen->lines[0] = {"HP: " + std::to_string(player->actualHealth())};
            screen->lines[1] = {message};
            screen->printScreen();
        }
    }
    return 0;
}