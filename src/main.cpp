#include "headers/interface.h"
#include "headers/mainMenu.h"
#include "headers/options.h"

void initialize(){
    initializeInterface();
    initializeOptions();
}

void finalize(){
    finalizeInterface();
    finalizeOptions();
}

int main(){
    initialize();
    runContext(new MainMenu());
    finalize();
    return 0;
}