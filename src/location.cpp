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
    std::vector<std::string> m{"",
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

    std::vector<std::string> m2 = this->map->getMap();

    m2[player_position.first][player_position.second] = 'p';

    for(int i = 0; i < m2.size(); ++i)
        m.insert(m.begin() + i + 4, "       " + m2[i]);
    
    print(m);
}

void Location::encounter(){
    std::vector<Character*> enemies = {new Enemy()};
    runContext(new Combat(enemies));
    this->show();
}
