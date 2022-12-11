#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;


fs::path saves;
fs::path shared_folder {"shared"};

int main(){
    saves = "saves";
    if(!fs::exists(saves))
        fs::create_directory(saves);
    saves = saves / "save1";
    if(fs::exists(saves))
        fs::remove_all(saves);
    fs::create_directory(saves);
    std::filesystem::copy(shared_folder, saves, std::filesystem::copy_options::recursive);

    return 0;
}