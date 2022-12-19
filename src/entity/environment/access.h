#ifndef ACCESS_H
#define ACCESS_H

#include "../entity.h"

class Access : public Entity {
    public:
        Access(int index, std::pair<int, int> exit_position);
        std::pair<int, int> getExit() override;
        char getSymbol() override;
        bool isAccess() override;
    private:
        std::pair<int, int> exit_position;
        
};

#endif