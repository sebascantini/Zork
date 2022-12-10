#ifndef Access_H
#define Access_H

#include "object.h"

class Access : public Object {
    public:
        Access(int index, std::pair<int, int> exit_position);
        std::pair<int, int> get_exit() override;
        bool isAccess() override;
    private:
        std::pair<int, int> exit_position;
        
};

#endif