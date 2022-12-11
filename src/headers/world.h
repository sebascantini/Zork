#ifndef WORLD_H
#define WORLD_H

#include "game.h"
#include "character.h"
#include "locationnode.h"
#include "location.h"
#include <vector>

class World : public Game{
    public:
        World(LocationNode* current_location);
        ~World();
        void next() override;
        void select() override;
        void show() override;
    private:
        LocationNode* current_location; //graph
        void changeLocation(int entrance_shift_x, int entrance_shift_y);
        void movePlayer(int shift_x, int shift_y) override ;
        void inventory();
        void settings();
        void quit();
        void attemptEncounter();
        void triggerEncounter();
};
 
#endif