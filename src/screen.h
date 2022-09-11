#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>

class Screen{
    public:
        Screen(std::string t, std::vector<std::string> c);
        virtual void printScreen();
        std::vector<std::string> lines;
    private:
        std::string title;
        std::vector<std::string> commands;
        void clear();
        void printLine(std::string s);
};

#endif