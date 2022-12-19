#include "interface.h"
#include "context/mainmenu.h"
#include "settings/settings.h"

void initialize(){
    initializeInterface();
    initializeSettings();
}

void finalize(){
    finalizeInterface();
    finalizeSettings();
}

int main(){
    initialize();
    MainMenu main_menu;
    main_menu.run();
    finalize();
    return 0;
}