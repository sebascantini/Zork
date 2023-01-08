#ifndef MAINMENU_H
#define MAINMENU_H

#include "maincontext.h"
#include "../other/gamemanager.h"

class MainMenu : public MainContext{
    public:
        MainMenu();
        void moveUp() override;
        void moveDown() override;
        void select() override;
    private:
        GameManager game_manager;
        void printTitle();
        void show() override;
};
 
#endif