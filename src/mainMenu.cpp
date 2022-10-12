#include "headers/interface.h"
#include "headers/locationManager.h"
#include "headers/mainMenu.h"

MainMenu::MainMenu(){
    this->show();
}

bool MainMenu::isActive(){
    return this->is_active;
}

void MainMenu::next(){
    getInput(this);
    show();
}

void MainMenu::moveUp(){
    this->selector = std::max(this->selector - 1, 0);
}

void MainMenu::moveDown(){
    this->selector = std::min(this->selector + 1, 3);
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
            this->exit();
            break;
    }
}

void MainMenu::newGame(){
    runContext(new LocationManager());
    this->selector = 0; // reset menu this->selector
}

void MainMenu::loadGame(){
    // coming soon
}

void MainMenu::settings(){
    // coming soon
}


void MainMenu::exit(){
    this->is_active = false;
}

std::string MainMenu::selection(int item){
    return (this->selector == item) ? "->" : "";
}

void MainMenu::show(){
    print({
        "",
        " ========= Combat ============================================================================== ",
        "",
        "",
        "             ==============     ==============     ==============     ||          //",
        "                         //     ||          ||     ||          ||     ||         //",
        "                        //      ||          ||     ||          ||     ||        //",
        "                       //       ||          ||     ||          ||     ||       //",
        "                      //        ||          ||     ||          ||     ||      //",
        "                     //         ||          ||     ||          ||     ||     //",
        "                    //          ||          ||     ||==========||     ||____//",
        "                   //           ||          ||     ||    \\\\           ||----\\\\",
        "                  //            ||          ||     ||     \\\\          ||     \\\\",
        "                 //             ||          ||     ||      \\\\         ||      \\\\",
        "                //              ||          ||     ||       \\\\        ||       \\\\",
        "               //               ||          ||     ||        \\\\       ||        \\\\",
        "              //                ||          ||     ||         \\\\      ||         \\\\",
        "             ==============     ==============     ||          \\\\     ||          \\\\",
        "",
        "",
        "                            Licence not owned and name is not final",
        "                                       pls don't sue uwu",
        " =============================================================================================== ",
        "",
        "    " + selection(0) + " New Game",
        "    " + selection(1) + " Continue (coming soon)",
        "    " + selection(2) + " Settings (coming soon)",
        "    " + selection(3) + " Quit",
        "",
        " =============================================================================================== ",
        "",
    });
}
