#include "headers/settings.h"
#include "headers/filesystem.h"

Settings* settings;

Settings::Settings(){
    this->controls = loadControls();
}

int Settings::getInputCode(int key_code){
    if(this->controls.find(key_code) == this->controls.end())
        return -1;
    return this->controls[key_code];
}