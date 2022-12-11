#include "headers/filesystem.h"
#include "headers/interface.h"
#include "headers/mainmenu.h"

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
            file_system->newGame();
            break;
        case 1:
            file_system->loadGame();
            break;
        case 2:
            this->settings();
            break;
        case 3:
            this->quit();
            break;
    }
    this->selector = 0; // reset menu this->selector
    this->show();
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
        this->selection(i++) + " New Game",
        this->selection(i++) + " Continue",
        this->selection(i++) + " Settings (coming soon)",
        this->selection(i++) + " Quit"
    });
}
