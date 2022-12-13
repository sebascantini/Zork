#include "headers/filesystem.h"
#include "headers/interface.h"
#include "headers/mainmenu.h"
#include "headers/settings.h"

void initialize(){
    initializeFileSystem();
    initializeInterface();
    initializeSettings();
}

void finalize(){
    finalizeFileSystem();
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