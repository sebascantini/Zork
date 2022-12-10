#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object{
    public:
        const std::string get_name();
        const char get_symbol();
        const int get_id();
        virtual std::pair<int, int> get_exit() {return {0, 0};};
        virtual bool isAccess();
        virtual bool isItem();
    protected:
        std::string name;
        char symbol;
        int id;
        
};

#endif