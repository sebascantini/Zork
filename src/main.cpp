#include "player.h"
#include "location.h"
#include <vector>

std::vector<void(*)(Environment*)> commands;
Player* player;
Environment* environment;

void boot(){
    commands = {};
    player = new Player();
    Map* m = new Map("test01");
    environment = new Location(m);
}

int main(){
    boot();
    while(environment->isActive()){
        environment->next();
    }
    delete(environment);
    delete(player);
}