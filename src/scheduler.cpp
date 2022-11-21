#include "headers/scheduler.h"

#define SCHEDULE_TABLE_SPEED 1
#define SCHEDULE_TABLE_PROGRESS 2
#define SCHEDULE_TABLE_PROGRESS_INIT 0
#define SCHEDULE_TABLE_PROGRESS_MAX 100

Scheduler::Scheduler(std::vector<Character*> &characters){ // player is in last position
    this->characters_ptr = &characters;
    for(int i = 0; i < characters.size(); ++i)
        this->scheduling_table.push_back({i, characters[i]->getSpeed(), SCHEDULE_TABLE_PROGRESS_INIT});
}
    
int Scheduler::next(){
    int next_index = 0;
    float fastest_time = __INT_MAX__;

    for(int i = 0; i < this->scheduling_table.size(); ++i){ //get character w
        if(this->scheduling_table[i][SCHEDULE_TABLE_PROGRESS] >= 100){ // if there was a tie, in previous function call, a character might already be  at 100.
            this->scheduling_table[i][SCHEDULE_TABLE_PROGRESS] = SCHEDULE_TABLE_PROGRESS_INIT;
            return i;
        }

        int current_time = (SCHEDULE_TABLE_PROGRESS_MAX - this->scheduling_table[i][SCHEDULE_TABLE_PROGRESS])/this->scheduling_table[i][SCHEDULE_TABLE_SPEED]; // time that would take current character to reach max progress

        if(current_time <= fastest_time){ // <= so that in returns the last fastest person (in case of a tie with the player, player has advantage)
            fastest_time = current_time;
            next_index = i;
        }
    }

    for(int i = 0; i < this->scheduling_table.size(); ++i) // update all characters progress
        this->scheduling_table[i][SCHEDULE_TABLE_PROGRESS] = this->scheduling_table[i][SCHEDULE_TABLE_PROGRESS] + (this->scheduling_table[i][SCHEDULE_TABLE_SPEED] * fastest_time);
    this->scheduling_table[next_index][SCHEDULE_TABLE_PROGRESS] = SCHEDULE_TABLE_PROGRESS_INIT; // reset progress
    return next_index;
}