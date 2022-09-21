#include "player.h"
#include "location.h"
#include <vector>

std::vector<void(*)(Environment*)> commands;
Player* player;
Environment* environment;

void boot(){
    commands = {};
    player = new Player();
    environment = new Location();
}

int main(){
    boot();
    while(environment->isActive()){
        environment->next();
    }
    delete(environment);
    delete(player);
}