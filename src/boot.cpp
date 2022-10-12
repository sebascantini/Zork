#include "headers/interface.h"
#include "headers/mainMenu.h"
#include "headers/options.h"
#include <iostream>

Options* options;

void boot(){
    initializeInterface();
    options = new Options();
}

void finalize(){
    delete(options);
    finalizeInterface();
}

int main(){
    boot();
    runContext(new MainMenu());
    std::cout << "corn" << std::endl;
    finalize();
    return 0;
}