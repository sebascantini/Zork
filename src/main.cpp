#include "player.h"
#include "location.h"
#include <vector>

Player* player;

void boot(){
    player = new Player();
}

int main(){
    boot();
    runContext(new Location(new Map("test01")));
    delete(player);
}