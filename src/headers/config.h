#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

const fs::path save_folder {"saves"};
extern fs::path save_path;

const fs::path settings_folder {"settings"};
const fs::path settings_default_folder {settings_folder / "default"};

const fs::path shared_folder {"shared"};
const fs::path map_folder {"maps"};
const fs::path world_file {map_folder / "connectivity.world"};

#endif