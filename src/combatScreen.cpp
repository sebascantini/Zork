#include "combatScreen.h"
#include "player.h"

void CombatScreen::show(){
    this->lines = {
        "",
        "COMBAT",
        "",
        "   Enemy Data",
        "",
        "",
        "HP: " + std::to_string(player->actualHealth()),
        "",
        "",
        ""
    };
    this->print();
}