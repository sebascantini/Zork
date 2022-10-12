#ifndef MAINMENU_H
#define MAINMENU_H

#include "context.h"

class MainMenu : public Context{
    public:
        MainMenu();
        bool isActive() override;
        void next() override;
        void moveUp() override;
        void moveDown() override;
        void select() override;
        void show() override;
    private:
        bool is_active = true;
        void newGame();
        void loadGame();
        void settings();
        void exit();
        std::string selection(int item);
};
 
#endif