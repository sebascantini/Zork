#ifndef GAME_H
#define GAME_H

#include "context.h"
#include "character.h"
#include "map.h"

class Game : public Context{
    public:
        Game();
        ~Game();
        bool isActive() override;
        void next() override;
    protected:
        Map* map;
        std::pair<int, int> player_position;
    private:
        bool is_active = true;
        std::vector<void (Game::*)()> commands;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void movePlayerTo(int row, int column);
        void exit();
        void changeMap();
        void show() override;
        void triggerEncounter();
};

#endif