#include "player.h"
#include <unistd.h>
#include "combatScheduler.h"

CombatScheduler::CombatScheduler(std::vector<Character*> &characters){ // player is in last position
    characters_ptr = &characters;
    for(int i = 0; i < characters.size(); ++i)
        scheduling_table.push_back({i, characters[i]->getSpeed(), 0});
}
    
int CombatScheduler::next(){
    int next_index = 0;
    float fastest_time = __INT_MAX__;

    sleep(1);

    for(int i = 0; i < scheduling_table.size(); ++i){
        if((*this->characters_ptr)[i]->getCurrentHealth() > 0){
        if(this->scheduling_table[i][2] >= 100){
            this->scheduling_table[i][2] = 0;
            return i;
        }

        int current_time = (100 - this->scheduling_table[i][2])/this->scheduling_table[i][1];

        if(current_time <= fastest_time){ // <= so that in returns the last fastest person (in case of a tie with the player, player has advantage)
            fastest_time = current_time;
            next_index = i;
        }
    }
    }

    for(int i = 0; i < scheduling_table.size(); ++i)
        scheduling_table[i][2] = scheduling_table[i][2] + (scheduling_table[i][1] * fastest_time);
    scheduling_table[next_index][2] = 0;
    return next_index;
}