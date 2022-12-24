#ifndef SETTINGS_H
#define SETTINGS_H

#include <unordered_map>
#include "../context/context.h"

class Settings : public Context{
    public:
        Settings();
        void moveUp() override;
        void moveDown() override;
        void options() override;
        void select() override;
        void open();
        int getInputCode(int key_code);
    private:
        std::unordered_map<int, int> controls;
        void loadControls();
        void show() {};
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