#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object{
    public:
        const std::string get_name();
        const char get_symbol();
        virtual int get_index() { return -1; };
        virtual std::pair<int, int> get_exit() {return {0, 0};};
        virtual bool isAccess();
    protected:
        std::string name;
        char symbol;
        
};

#endif