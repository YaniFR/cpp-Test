#include "../Include/Entity.hpp"
#include <string>
using namespace std;

void Entity::remaining_HP(size_t damage){
    if (Stats["HP"]- damage <= 0.0)
        Stats["HP"]= 0.0;
    else 
        Stats["HP"]-= damage;

};

size_t Entity::get_value(std::string stat){
    return Stats[stat];
}

void Entity::stats_change(std::string stat, int change){
    if (!change){
        if((Stats[stat] - change) > 0){
            Stats[stat] -= change;
        }
        else{
            Stats[stat] = 0;
        }
    }
    else{
        Stats[stat] += change;
    }
};

std::string Entity::get_name(){
    return Name;
}

Entity::Entity(t_map map, std::string str)
    : Stats(map), Name(str){};