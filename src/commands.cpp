#include "commands.h"


void attack(Environment *environment){
    environment->environmentAttack();
}

void useItem(Environment *environment){
    environment->environmentUseItem();
}

void run(Environment *environment){
    environment->environmentRun();
}

void options(Environment *environment){
    environment->environmentOptions();
}