#include "headers/options.h"
#include "headers/fileSystem.h"

Options* options;

Options::Options(){
    this->controls = loadControls();
}

int Options::getInputCode(int key_code){
    if(this->controls.find(key_code) == this->controls.end())
        return -1;
    return this->controls[key_code];
}

void initializeOptions(){
    options = new Options;
}

void finalizeOptions(){
    delete(options);
}