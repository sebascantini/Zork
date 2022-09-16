#include "interface.h"
#include "player.h"
#include <string>

std::string Player::turn(){
    std::string msg = "";
    while(msg == ""){
        switch(stoi(askForInput())){
            case 1:
                msg = "attack";
                break;
            case 2:
                msg = "use item";
                break;
            case 3:
                msg = "run";
                break;
        }
    }
    return msg;
}