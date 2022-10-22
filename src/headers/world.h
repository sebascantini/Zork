#ifndef WORLD_H
#define WORLD_H

#include "context.h"
#include "character.h"
#include "locationnode.h"
#include "location.h"
#include <vector>

class World : public Context{
    public:
        World();
        ~World();
        void next() override;
        void moveUp() override;
        void moveDown() override;
        void moveLeft() override;
        void moveRight() override;
        void options() override;
        void show() override;
    private:
        LocationNode* current_location; //graph
        Location* location;
        void changeLocation(int entrance_shift_x, int entrance_shift_y);
        void movePlayer(int shift_x, int shift_y);
        void attemptEncounter();
        void triggerEncounter();
};
 
#endif