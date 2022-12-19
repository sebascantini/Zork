#ifndef MENUSELECTOR_H
#define MENUSELECTOR_H

#include <string>

class MenuSelector{
    public:
        MenuSelector() {}
        MenuSelector(int start, int max);
        void toggle();
        void increase();
        void decrease();
        int getValue();
        std::string show (int value);
    private:
        int value;
        int max;
};

#endif