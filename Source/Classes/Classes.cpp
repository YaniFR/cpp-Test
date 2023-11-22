#include "../../Include/Classes/Classes.hpp"
#include <filesystem>
#include <string>
#include <iostream>
#include "../../Include/Classes/Warrior.hpp"
#include "../../Include/Player.hpp"
#include "Classes.hpp"
#include "Warrior.hpp"
#include "../../Include/Player.hpp"

Classes::Classes(std::string classe){

};

Classes::Classes(){

};

std::string Classes::get_name(){
    return Name;
};


t_map Classes::get_Stats(){
    return Stats;
};
