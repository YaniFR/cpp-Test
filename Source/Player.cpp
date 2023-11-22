#include "../Include/Player.hpp"
#include <string>
#include "../Include/Classes/Classes.hpp"
#include "Classes.hpp"
#include <iostream>
#include "../Classes/Warrior.hpp"



Player::Player(std::string str){
    Name = str;
    init_class();
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
