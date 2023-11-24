#include "../Include/Player.hpp"
#include <string>
#include "../Include/Classes/Classes.hpp"
#include "Classes.hpp"
#include <iostream>
#include "../Classes/Warrior.hpp"
#include "../Include/Enemy/Enemy.hpp"
#include "../Include/Enemy/Zombie.hpp"

Player::Player(std::string str){
    Name = str;
    init_class();
    set_classe("Warrior");
};


enemy_map Player::Enemy_map = {
    {"Zombie", Zombie()}
};


void Player::set_classe(std::string classe){
    if(classe_exists(classe)){
        Classe = Classes_map[classe];
        set_stats(Classe);
    }else{
        std::cout << "Classe not found" << std::endl;
    }
};

void Player::set_stats(class Classes Classe){    
    Stats = Classe.get_Stats();

};

void Player::init_class(){
    Classes_map["Warrior"] = Warrior();
}

bool Player::classe_exists(std::string classe){
    return Classes_map.find(classe) != Classes_map.end();
};

std::vector<std::string> Player::get_Classes(){
    std::vector<std::string> classes;
    for(auto const& x : Classes_map){
        classes.push_back(x.first);
    }
    return classes;
};
