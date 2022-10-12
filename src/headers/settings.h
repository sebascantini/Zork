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

//input key codes
#define KEY_CODE_UP 1
#define KEY_CODE_DOWN 2
#define KEY_CODE_LEFT 3
#define KEY_CODE_RIGHT 4
#define KEY_CODE_OPTIONS 5

#endif