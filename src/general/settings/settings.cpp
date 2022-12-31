#include "settings.h"
#include "paths.h"
#include <fstream>
#include <curses.h>

Settings* settings;

Settings::Settings(){
    settings = this;
    this->loadControls();
}

void Settings::options(){
    std::ofstream file (settings_folder / "controls");
    for(auto& entry : this->controls)
        file << entry.first << " " << entry.second << std::endl;
    this->exit();
}

void Settings::open(){
    this->selector = MenuSelector(0, this->controls.size());
    this->show();
    this->run();
}

void Settings::moveUp(){
    this->selector.decrease();
}

void Settings::moveDown(){
    this->selector.increase();
}

void Settings::select(){
    int new_key = this->getKey();
    int temp;
    for(auto& entry : this->controls){
        if(entry.second == this->selector.getValue()){
            temp = entry.first;
        }
    }
    this->controls.erase(temp);
    this->controls[new_key] = this->selector.getValue();
}

int Settings::getInputCode(int key_code){
    if(this->controls.find(key_code) == this->controls.end())
        return -1;
    return this->controls[key_code];
}

void Settings::loadControls(){
    std::ifstream file (settings_folder / "controls");
    int key_code, key_id;
    
    if(!file.is_open()){
        fs::copy(settings_default_folder / "controls", settings_folder/ "controls");
        file.open(settings_folder / "controls");
    }

    while(file >> key_code){
        file >> key_id;
        this->controls[key_code] = key_id;
    }
}

void initializeSettings(){
    settings = new Settings();
}

void finalizeSettings(){
    delete(settings);
}