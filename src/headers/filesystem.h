#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <filesystem>
#include "locationnode.h"
#include "location.h"
#include <unordered_map>

namespace fs = std::filesystem;

class FileSystem{
    public:
        void newGame();
        void loadGame();
        LocationNode* loadWorld();
    private:
        void createNewGameFiles();
};

extern FileSystem* file_system;

void initializeFileSystem();
void finalizeFileSystem();

#endif