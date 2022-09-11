#include "interface.h"
#include "player.h"

std::string Player::turn(){
    askForInput();
    return "you did nothing";
}