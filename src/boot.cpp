#include "player.h"
#include "world.h"

Player* player;

int main(){
    player = new Player();
    runContext(new World());
    delete(player);
    return 0;
}