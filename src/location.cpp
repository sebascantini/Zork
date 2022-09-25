#include "combat.h"
#include "interface.h"
#include "enemy.h"
#include "location.h"

Location::Location(Map& m){
    this->encounter();
    this->show();
}

bool Location::isActive(){
    return false;
}

void Location::next(){
    
}

void Location::environmentMoveUp(){
    
}

void Location::environmentMoveDown(){
    
}

void Location::environmentMoveLeft(){
    
}

void Location::environmentMoveRight(){
    
}

void Location::show(){
        print({
        "",
        " ========= Location ============================================================================== ",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        " =============================================================================================== ",
        "",
        "",
        "    1. A",
        "    2. B",
        "    3. C",
        "    4. D",
        "",
        "",
        " =============================================================================================== ",
        "",
    });
}

void Location::encounter(){
    Environment* self = environment;
    std::vector<Character*> enemies = {new Enemy()};
    environment = new Combat(enemies);
        while(environment->isActive()){
        environment->next();
    }
    delete(enemies[0]);
    delete(environment);
    environment = self;
    this->show();
}
