#ifndef INTERFACE_H
#define INTERFACE_H

#include "context.h"
#include "settings.h"
#include <string>
#include <vector>

class Interface{
    public:
        Interface();
        ~Interface();
        const int getKey();
        void getInput(Context* context);
        void print(std::vector<std::string> screen);
        void inject(); //?
        void refresh(); //?
    private:
        void printLine(std::string s);
        Settings settings;
};

void initializeInterface();
void finalizeInterface();

extern Interface* interface;

#endif