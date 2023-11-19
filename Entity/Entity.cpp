#include "Entity.hpp"
#include <string>
using namespace std;

double Entity::remaining_HP(double &HP, double damage){
    if (HP == 0.0 || HP - damage < 0.0){
        HP = 0.0;
        return HP;
    }
    else{
        HP -= damage;
        return HP;
    }

};

Entity::Entity(){};

Entity::Entity(double x, std::string str){
    HP = x;
    Name = str;
};