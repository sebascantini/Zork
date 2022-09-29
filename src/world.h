#ifndef WORLD_H
#define WORLD_H

#include "context.h"
#include "character.h"
#include "locationManager.h"
#include <vector>

class World : public Context{
    public:
        World();
        ~World();
        bool isActive() override;
        void next() override;
    private:
        bool is_active = true;
        std::vector<void (World::*)()> commands;
        LocationManager* location_manager;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void exit();
        void show() override;
};

#endif