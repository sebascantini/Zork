#ifndef LOCATION_H
#define LOCATION_H

#include "environment.h"
#include "character.h"
#include "map.h"

class Location : public Environment{
    public:
        Location(Map* m);
        bool isActive() override;
        void next() override;
        void environmentMoveUp() override;
        void environmentMoveDown() override;
        void environmentMoveLeft() override;
        void environmentMoveRight() override;
    protected:
        Map* map;
        std::pair<int, int> player_position;
    private:
        void show() override;
        void encounter();
};

#endif