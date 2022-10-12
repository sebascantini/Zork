#ifndef OPTIONS_H
#define OPTIONS_H

#include <unordered_map>

class Options{
    public:
        Options();
        int getInputCode(int key_code);
    private:
        std::unordered_map<int, int> controls;
};

void initializeOptions();
void finalizeOptions();

extern Options* options;

//input key codes
#define KEY_CODE_UP 1
#define KEY_CODE_DOWN 2
#define KEY_CODE_LEFT 3
#define KEY_CODE_RIGHT 4
#define KEY_CODE_OPTIONS 5

#endif