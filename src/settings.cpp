#include "headers/settings.h"
#include "headers/fileSystem.h"

Settings* settings;

Settings::Settings(){
    this->controls = loadControls();
}

int Settings::getInputCode(int key_code){
    if(this->controls.find(key_code) == this->controls.end())
        return -1;
    return this->controls[key_code];
}

void initializeSettings(){
    settings = new Settings;
}

void finalizeSettings(){
    delete(settings);
}