#include "game.h"
#include "player.h"
#include "world.h"

Player* player;

int main(){
    player = new Player();
    loadWorld();
    runContext(new Game());
    unloadWorld();
    delete(player);
    return 0;
}