#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H

#include "context.h"
#include "character.h"
#include "locationNode.h"
#include "locationPackage.h"
#include <vector>

class LocationManager : public Context{
    public:
        LocationManager();
        ~LocationManager();
        bool isActive() override;
        void next() override;
        void moveUp() override;
        void moveDown() override;
        void moveLeft() override;
        void moveRight() override;
        void options() override;
    private:
        bool is_active = true;
        LocationNode* current_location;
        LocationPackage* location_data;
        void changeLocation(int entrance_shift_x, int entrance_shift_y);
        void movePlayer(int shift_x, int shift_y);
        void show() override;
        void attemptEncounter();
        void triggerEncounter();
};
 
#endif