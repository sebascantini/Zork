#ifndef LOCATION_H
#define LOCATION_H

#include "environment.h"
#include "character.h"

class Location : public Environment{
    public:
        Location();
        bool isActive() override;
        void next() override;
        void environmentMoveUp() override;
        void environmentMoveDown() override;
        void environmentMoveLeft() override;
        void environmentMoveRight() override;
    private:
        void show() override;
        void encounter();
};

#endif