#include "combat.h"
#include "player.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>

Combat::Combat(std::vector<Character*> e){
    screen = new CombatScreen();
    screen->show();
}                  