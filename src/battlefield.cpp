#include "headers/battlefield.h"

#define BATTLEFIELD_HEIGHT 7
#define BATTLEFIELD_WIDTH 9

Battlefield::Battlefield(std::vector<Character*> &characters){
    this->name = "Battlefield";
    this->characters = &characters; 
    this->setCharacterPositions();
    this->setMap();
}

void Battlefield::setCharacterPositions(){
    for(int i = 0; i < (*this->characters).size(); ++i)
        this->character_positions[(*this->characters)[i]] = std::make_pair(3, 7); //FIXME only works for single enemy
    this->character_positions[(*this->characters)[(*this->characters).size() - 1]] = std::make_pair(3,1); // place player 
}

void Battlefield::setMap(){
    this->map = std::vector<std::string>(BATTLEFIELD_HEIGHT, std::string(BATTLEFIELD_WIDTH, '.'));
}