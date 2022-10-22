#include "headers/interface.h"
#include "headers/mainmenu.h"

void initialize(){
    initializeInterface();
}

void finalize(){
    finalizeInterface();
}

int main(){
    initialize();
    MainMenu main_menu;
    main_menu.run();
    finalize();
    return 0;
}