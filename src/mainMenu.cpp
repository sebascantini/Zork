#include "headers/interface.h"
#include "headers/locationManager.h"
#include "headers/mainMenu.h"
#include "headers/player.h"

MainMenu::MainMenu(){
    this->show();
}

void MainMenu::next(){
    interface->getInput(this);
}

void MainMenu::moveUp(){
    this->selector = std::max(this->selector - 1, 0);
    this->show();
}

void MainMenu::moveDown(){
    this->selector = std::min(this->selector + 1, 3);
    this->show();
}

void MainMenu::select(){
    switch(this->selector){
        case 0:
            this->newGame();
            break;
        case 1:
            this->loadGame();
            break;
        case 2:
            this->settings();
            break;
        case 3:
            this->quit();
            break;
    }
    this->show();
}

void MainMenu::newGame(){
    initializePlayer();
    LocationManager location_manager;
    location_manager.run();
    deletePlayer();
    this->selector = 0; // reset menu this->selector
}

void MainMenu::loadGame(){
    // coming soon
}

void MainMenu::settings(){
    // coming soon
}

void MainMenu::quit(){
    this->exit();
}

void MainMenu::show(){
    int i = 0;
    interface->printTop({
        "==============     ==============     ==============     ||          //",
        "            //     ||          ||     ||          ||     ||         //",
        "           //      ||          ||     ||          ||     ||        //",
        "          //       ||          ||     ||          ||     ||       //",
        "         //        ||          ||     ||          ||     ||      //",
        "        //         ||          ||     ||          ||     ||     //",
        "       //          ||          ||     ||==========||     ||____//",
        "      //           ||          ||     ||    \\\\           ||----\\\\",
        "     //            ||          ||     ||     \\\\          ||     \\\\",
        "    //             ||          ||     ||      \\\\         ||      \\\\",
        "   //              ||          ||     ||       \\\\        ||       \\\\",
        "  //               ||          ||     ||        \\\\       ||        \\\\",
        " //                ||          ||     ||         \\\\      ||         \\\\",
        "==============     ==============     ||          \\\\     ||          \\\\",
        "",
        "",
        "               Licence not owned and name is not final",
        "                          pls don't sue uwu"
    });
    interface->printBot({
        selection(i++) + " New Game",
        selection(i++) + " Continue (coming soon)",
        selection(i++) + " Settings (coming soon)",
        selection(i++) + " Quit"
    });
}
