#ifndef GAME_H
#define GAME_H

#include "context.h"
#include "location.h"
#include <vector>

class Game : public Context{
    public:
        virtual void next() override {}
        void moveUp() override;
        void moveDown() override;
        void moveLeft() override;
        void moveRight() override;
        void options() override;
    protected:
        virtual void movePlayer(int shift_x, int shift_y) {}
        Location* location;
    private:
        bool moving = true;
};
 
#endif