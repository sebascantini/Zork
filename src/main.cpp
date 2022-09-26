#include "player.h"
#include "location.h"
#include <vector>

Player* player;
std::vector<std::string> maps;

void boot(){
    player = new Player();
    maps = {"test01"};
}

int main(){
    boot();
    runContext(new Location(0));
    delete(player);
}