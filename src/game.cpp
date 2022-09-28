#include "combat.h"
#include "interface.h"
#include "probability.h"
#include "enemy.h"
#include "world.h"
#include "game.h"

Game::Game(){
    this->commands = {&Game::moveUp, &Game::moveDown, &Game::moveLeft, &Game::moveRight, &Game::exit};
    std::pair<Map*, std::pair<int, int>> newLocationPackage = loadLocation(0);
    this->map = newLocationPackage.first;
    this->player_position = newLocationPackage.second;
    this->show();
}

Game::~Game(){
    delete(this->map);
}

bool Game::isActive(){
    return this->is_active;
}

void Game::next(){
    int input = askForInt(this->commands.size());
    (this->*this->commands[input - 1])();
    this->show();
}

void Game::moveUp(){
    this->movePlayerTo(this->player_position.first - 1, this->player_position.second);
}

void Game::moveDown(){
    this->movePlayerTo(this->player_position.first + 1, this->player_position.second);
}

void Game::moveLeft(){
    this->movePlayerTo(this->player_position.first, this->player_position.second - 1);
}

void Game::moveRight(){
    this->movePlayerTo(this->player_position.first, this->player_position.second + 1);
}

void Game::movePlayerTo(int row, int column){
    if(map->isValid(row, column))
        this->player_position = std::make_pair(row, column);
    this->changeMap();
    if(chance(15))
        this->triggerEncounter();
}

void Game::changeMap(){
    int next_map_edge = map->getNextMapEdge(this->player_position);
    if(next_map_edge == -1)
        return;

    delete(map);
    std::pair<Map*, std::pair<int, int>> newLocationPackage = moveLocation(next_map_edge);
    this->map = newLocationPackage.first;
    this->player_position = newLocationPackage.second;
}

void Game::exit(){
    this->is_active = false;
}

void Game::show(){
    std::vector<std::string> screen{"",
        " ========= Game ============================================================================== ",
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
        "    5. Quit"
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

void Game::triggerEncounter(){
    std::vector<Character*> enemies = {new Enemy()};
    runContext(new Combat(enemies));
    this->show();
}
