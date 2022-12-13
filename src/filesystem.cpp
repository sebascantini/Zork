#include <fstream>
#include "headers/filesystem.h"
#include "headers/world.h"
#include "headers/config.h"
#include <sstream>

#define MAP_FILE_EXTENTION ".location"

FileSystem* file_system;

void FileSystem::newGame(){
    this->createNewGameFiles();
    this->loadGame();
}

void FileSystem::loadGame(){
    World world (this->loadWorld());
    world.run();
}

LocationNode* FileSystem::loadWorld(){
    std::ifstream connectivity_file (save_path / world_file);
    
    std::string temporary_file_line;
    std::vector<std::istringstream*> location_streams;
    std::vector<LocationNode*> locations;


    while(std::getline(connectivity_file, temporary_file_line)){
        std::istringstream* file_line = new std::istringstream (temporary_file_line);
        location_streams.push_back(file_line);
    }

    connectivity_file.close();

    for(int i = 0; i < location_streams.size(); ++i){
        std::string file_name;
        *location_streams[i] >> file_name;
        locations.push_back(new LocationNode(file_name));
    }

    for(int i = 0; i < locations.size(); ++i){
        int location_index;
        while(*location_streams[i] >> location_index)
            locations[i]->addNearbyLocation(locations[location_index]);
    }

    for(int i = 0; i < location_streams.size(); ++i)
        delete(location_streams[i]);
        
    return locations[0];
}

void FileSystem::createNewGameFiles(){
    if(!fs::exists(save_folder))
        fs::create_directory(save_folder);
    if(fs::exists(save_path))
        fs::remove_all(save_path);
    fs::create_directory(save_path);
    std::filesystem::copy(shared_folder, save_path, std::filesystem::copy_options::recursive);
}

void initializeFileSystem(){
    file_system = new FileSystem();
}

void finalizeFileSystem(){
    delete(file_system);
}