#include "curses.h"

int main(){
    initscr();
    timeout(-1);
    int c = getch();
    printf("%d\n", (int) c);
    c = getch();
    printf("%d\n", (int) c);
        c = getch();
    printf("%d\n", (int) c);
        c = getch();
    printf("%d\n", (int) c);
    endwin();
    return 0;
}