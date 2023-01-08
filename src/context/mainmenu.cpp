#include "mainmenu.h"
#include "../settings/paths.h"
#include "settings.h"

MainMenu::MainMenu(){
    this->setWindows();
    this->selector = MenuSelector(0, 3);
    this->show();
    this->run();
}

void MainMenu::moveUp(){
    this->selector.decrease();
    this->show();
}

void MainMenu::moveDown(){
    this->selector.increase();
    this->show();
}

void MainMenu::select(){
    switch(this->selector.getValue()){
        case 0:
            this->game_manager.newGame();
            break;
        case 1:
            this->game_manager.loadGame();
            break;
        case 2:
            settings->open();
            break;
        case 3:
            this->exit();
            break;
    }
}

void MainMenu::show(){
    int i = 0;
    this->printTop({
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
    this->printBot({
        this->selector.show(i++) + " New Game",
        this->selector.show(i++) + " Continue",
        this->selector.show(i++) + " Settings (coming soon)",
        this->selector.show(i++) + " Quit"
    });
}
