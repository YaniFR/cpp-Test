#include "../Include/Entity.hpp"
#include <string>
using namespace std;

void Entity::remaining_HP(double damage){
    if (Stats["HP"]- damage <= 0.0){
        Stats["HP"]= 0.0;
        set_status("Dead");
    }
    else
        Stats["HP"]-= damage;  
};

t_map Entity::get_stats(){
    return Stats;
}

string Entity::get_status(){
    return status;
}

void Entity::set_status(string str){
    status = str;
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

double Entity::get_stat(std::string stat){
    return Stats[stat];
}

double Entity::get_health(){
    return Stats["HP"];
}

std::string Entity::get_name(){
    return Name;
}

Entity::Entity(t_map map, std::string str)
    : Stats(map), Name(str){};