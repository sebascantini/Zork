#include "headers/interface.h"
#include "headers/mainMenu.h"
#include "headers/settings.h"

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
    runContext(new MainMenu());
    finalize();
    return 0;
}