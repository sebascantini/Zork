#ifndef MAINMENU_H
#define MAINMENU_H

#include "context.h"
#include "../gamemanager.h"

class MainMenu : public Context{
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