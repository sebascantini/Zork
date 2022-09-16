#include "player.h"
#include "combatScheduler.h"

CombatScheduler::CombatScheduler(std::vector<Character*> enemies){
    characters = enemies;
    characters.push_back(player);
    
    for(int i = 0; i < characters.size(); ++i)
        scheduling_table.push_back({i, characters[i]->getSpeed(), 0});
}
    
Character* CombatScheduler::next(){
    int next_index = 0;
    float fastest_time = __INT_MAX__;

    for(int i = 0; i < scheduling_table.size(); ++i){
        if(scheduling_table[i][2] >= 100)
            return characters[i];

        int current_time = (100 - scheduling_table[i][2])/scheduling_table[i][1];

        if(current_time < fastest_time){
            fastest_time = current_time;
            next_index = i;
        }
    }

    for(int i = 0; i < scheduling_table.size(); ++i)
        scheduling_table[i][2] = scheduling_table[i][2] + (scheduling_table[i][1] * fastest_time);

    return characters[next_index];
}

bool CombatScheduler::combatContinues(){
    return player->getCurrentHealth() > 0 && characters.size() > 1;
}