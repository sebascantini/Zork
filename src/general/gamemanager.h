#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager{
    public:
        GameManager() {}
        void newGame();
        void loadGame();
    private:
        void createNewGameFiles();
};

#endif