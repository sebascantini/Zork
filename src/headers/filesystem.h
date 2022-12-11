#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <filesystem>
#include "locationnode.h"
#include "location.h"
#include <unordered_map>

namespace fs = std::filesystem;

class FileSystem{
    public:
        void setNewGameFiles();
        std::unordered_map<int, int> loadControls();
        LocationNode* loadWorld();
        Location* loadLocation(std::string file_name);
    private:
        fs::path current_save;
        const fs::path saves {"saves"};
        const fs::path settings_folder {"settings"};
        const fs::path settings_default_folder {settings_folder / "default"};
        const fs::path shared_folder {"shared"};
        const fs::path map_folder {"maps"};
        const fs::path world_file {map_folder / "connectivity.world"};
        std::ifstream loadOptions(std::string file_name);
};

extern FileSystem* file_system;

void initializeFileSystem();
void finalizeFileSystem();

#endif