#include "headers/filesystem.h"
#include "headers/interface.h"
#include "headers/mainmenu.h"

void initialize(){
    initializeFileSystem();
    initializeInterface();
}

void finalize(){
    finalizeFileSystem();
    finalizeInterface();
}

int main(){
    initialize();
    MainMenu main_menu;
    main_menu.run();
    finalize();
    return 0;
}