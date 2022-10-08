#include "headers/player.h"
#include "headers/locationManager.h"
#include "headers/options.h"
#include "headers/interface.h"

Player* player;
Options* options;

int main(){
    initiateScreen();
    options = new Options();
    player = new Player();
    runContext(new LocationManager());
    delete(player);
    delete(options);
    deleteScreen();
    return 0;
}