#ifndef GAME_H
#define GAME_H

#include "context.h"
#include "../../entity/characters/character.h"
#include "../../world/locationnode.h"
#include "../../world/location.h"
#include <vector>

class Game : public Context{
    public:
        Game();
        ~Game();
        void load();
        void moveUp() override;
        void moveDown() override;
        void moveLeft() override;
        void moveRight() override;
        void options() override;
        void select() override;
    private:
        bool moving = true;
        Location* location;
        LocationNode* current_location; //graph
        void show() override;
        void settings();
        void inventory();
        void changeLocation();
        void loadWorld();
};

#endif