#ifndef SETTINGS_H
#define SETTINGS_H

#include <unordered_map>

class Settings{
    public:
        Settings();
        int getInputCode(int key_code);
    private:
        std::unordered_map<int, int> controls;
};

void initializeSettings();
void finalizeSettings();

extern Settings* settings;

enum KEY_CODES {
    KEY_CODE_UP, 
    KEY_CODE_DOWN, 
    KEY_CODE_LEFT, 
    KEY_CODE_RIGHT, 
    KEY_CODE_SELECT, 
    KEY_CODE_OPTIONS
};

#endif