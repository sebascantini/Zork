#ifndef MAINMENU_H
#define MAINMENU_H

#include "context.h"

class MainMenu : public Context{
    public:
        MainMenu();
        ~MainMenu();
        bool isActive() override;
        void next() override;
    private:
        bool is_active = true;
        void exit();
        void show() override;
};
 
#endif