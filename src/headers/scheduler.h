#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "character.h"

class Scheduler{
    public:
        Scheduler(std::vector<Character*> &characters);
        int next();
    private:
        std::vector<std::vector<int>> scheduling_table;
        std::vector<Character*> *characters_ptr;
};

#endif