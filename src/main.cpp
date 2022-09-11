#include "player.h"
#include "enemy.h"
#include "combat.h"

Player* player;

int main(){
    player = new Player();
    Combat({new Enemy()});
    delete(player);
}