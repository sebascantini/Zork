#include "player.h"
#include "enemy.h"
#include "combat.h"
#include <vector>

std::vector<void(*)(Environment*)> commands;
Player* player;
Environment* environment;

void boot(){
    commands = {};
    player = new Player();
    environment = new Combat({new Enemy()});
}

int main(){
    boot();
    while(environment->isActive()){
        environment->next();
    }
    delete(environment);
    delete(player);
}