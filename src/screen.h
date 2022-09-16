#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>

class Screen{
    protected:
        std::vector<std::string> lines;
        void print();
    private:
        void printLine(std::string s);
};

#endif