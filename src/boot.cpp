#include <cstdlib>
#include "combat.h"
#include "iostream"
#include <string>

Player* player;

int main (){
    player = new Player();
    std::vector<Character*> enemies;
    enemies.push_back(new Enemy());
    combat(enemies);
    return 0;
}