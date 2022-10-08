#include "headers/interface.h"
#include "headers/mainMenu.h"
#include "headers/options.h"

Options* options;

int main(){
    initiateScreen();
    options = new Options();
    MainMenu *main_menu = new MainMenu();
    runContext(main_menu);
    deleteScreen();
    return 0;
}