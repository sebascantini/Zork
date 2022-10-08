#include "headers/player.h"
#include "headers/locationManager.h"

Player* player;

int main(){
    player = new Player();
    runContext(new LocationManager());
    delete(player);
    return 0;
}