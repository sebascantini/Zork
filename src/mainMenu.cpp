#include "headers/locationManager.h"
#include "headers/mainMenu.h"

MainMenu::MainMenu(){

}

MainMenu::~MainMenu(){

}

bool MainMenu::isActive(){
    return this->is_active;
}

void MainMenu::next(){
    LocationManager* location_manager = new LocationManager();
    runContext(location_manager);
    this->exit();
}

void MainMenu::exit(){
    this->is_active = false;
}

void MainMenu::show(){
    
}
