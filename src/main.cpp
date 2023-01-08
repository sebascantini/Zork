#include "context/mainmenu.h"
#include "context/settings.h"

void initialize(){
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    refresh();
    initializeSettings();
}

void finalize(){
    endwin();
    finalizeSettings();
}

int main(){
    initialize();
    MainMenu main_menu;
    finalize();
    return 0;
}