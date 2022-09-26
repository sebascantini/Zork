#include "combat.h"
#include "interface.h"
#include "enemy.h"
#include "location.h"

Location::Location(Map* m){
    this->map = m;
    this->player_position = map->getEntranceFrom(0);
    this->show();
}

bool Location::isActive(){
    return false;
}

void Location::next(){
    
}

void Location::show(){
    std::vector<std::string> screen{"",
        " ========= Location ============================================================================== ",
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
        ""}
    ;

    std::vector<std::string> map_copy = this->map->getMap();

    map_copy[player_position.first][player_position.second] = 'p'; // place player in map

    for(int i = 0; i < map_copy.size(); ++i) // insert map
        screen.insert(screen.begin() + i + 4, "       " + map_copy[i]);
    
    print(screen);
}

void Location::encounter(){
    std::vector<Character*> enemies = {new Enemy()};
    runContext(new Combat(enemies));
    this->show();
}
