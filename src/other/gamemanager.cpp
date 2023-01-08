#include "gamemanager.h"
#include "../context/game.h"
#include "../config/paths.h"
#include <filesystem>

fs::path save_path;

void GameManager::newGame(){
    save_path = save_folder / "save1";
    this->createNewGameFiles();
    this->loadGame();
}

void GameManager::loadGame(){
    save_path = save_folder / "save1";
    Game game;
}

void GameManager::createNewGameFiles(){
    if(!fs::exists(save_folder))
        fs::create_directory(save_folder);
    if(fs::exists(save_path))
        fs::remove_all(save_path);
    fs::create_directory(save_path);
    std::filesystem::copy(shared_folder, save_path, std::filesystem::copy_options::recursive);
}