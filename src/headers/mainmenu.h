#ifndef MAINMENU_H
#define MAINMENU_H

#include "context.h"

class MainMenu : public Context{
    public:
        MainMenu();
        void next() override;
        void moveUp() override;
        void moveDown() override;
        void select() override;
        void show() override;
    private:
        void printTitle();
        void settings();
        void quit();
};
 
#endif