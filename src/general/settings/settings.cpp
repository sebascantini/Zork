#include "settings.h"
#include "paths.h"
#include <fstream>

Settings* settings;

Settings::Settings(){
    this->loadControls();
}

int Settings::getInputCode(int key_code){
    if(this->controls.find(key_code) == this->controls.end())
        return -1;
    return this->controls[key_code];
}

void Settings::loadControls(){
    std::ifstream file (settings_folder / "controls");
    int key_code, key_id = 0;
    
    if(!file.is_open()){
        fs::copy(settings_default_folder / "controls", settings_folder/ "controls");
        file.open(settings_folder / "controls");
    }

    while(file >> key_code){
        this->controls[key_code] = key_id;
        key_id++;
    }
}

void initializeSettings(){
    settings = new Settings();
}

void finalizeSettings(){
    delete(settings);
}