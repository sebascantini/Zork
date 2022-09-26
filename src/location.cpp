#include "combat.h"
#include "interface.h"
#include "probability.h"
#include "enemy.h"
#include "location.h"

Location::Location(Map* m){
    this->commands = {&Location::moveUp, &Location::moveDown, &Location::moveLeft, &Location::moveRight};
    this->map = m;
    this->player_position = map->getEntranceFrom(0);
    this->show();
}

bool Location::isActive(){
    return true;
}

void Location::next(){
    int input = askForInt(this->commands.size());
    (this->*this->commands[input - 1])();
    this->show();
}

void Location::moveUp(){
    this->movePlayerTo(this->player_position.first - 1, this->player_position.second);
}

void Location::moveDown(){
    this->movePlayerTo(this->player_position.first + 1, this->player_position.second);
}

void Location::moveLeft(){
    this->movePlayerTo(this->player_position.first, this->player_position.second - 1);
}

void Location::moveRight(){
    this->movePlayerTo(this->player_position.first, this->player_position.second + 1);
}

void Location::movePlayerTo(int row, int column){
    if(map->isValid(row, column))
        this->player_position = std::make_pair(row, column);
    if(chance(15))
        this->triggerEncounter();
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
        "    1. Move Up",
        "    2. Move Down",
        "    3. Move Left",
        "    4. Move Right",
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

void Location::triggerEncounter(){
    std::vector<Character*> enemies = {new Enemy()};
    runContext(new Combat(enemies));
    this->show();
}
