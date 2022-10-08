#include "headers/options.h"

Options::Options(){
    this->controls[119] = KEY_CODE_UP;
    this->controls[115] = KEY_CODE_DOWN;
    this->controls[97] = KEY_CODE_LEFT;
    this->controls[100] = KEY_CODE_RIGHT;
    this->controls[27] = KEY_CODE_OPTIONS;
}

int Options::getInputCode(int key_code){
    if(this->controls.find(key_code) == this->controls.end())
        return -1;
    return this->controls[key_code];
}