#include "../Include/Inventory.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>
#include "../Include/Potions/small_Potion.hpp"
#include "../Include/Weapons/Sword.hpp"
#include "../Include/Potions/Potions.hpp"
#include <algorithm>
#include "../Include/Potions/large_Potion.hpp"
#include "../Include/Potions/Gourde_Du_Brave.hpp"

Inventory::Inventory(){
    add_Potions(small_Potion(),2);
    add_Weapons(Sword(),4);
    add_Potions(small_Potion(),2);
    add_Potions(large_Potion(),2);
    add_Potions(Gourde_Du_Brave(),12);
};

void Inventory::print(){
    for (const auto& potion : Potions) {
            std::cout << potion.first.Name << " " << potion.second << std::endl;
        }
    for(class Weapons &weapon : Weapons){
        std::cout << weapon.Name << std::endl;
    }
};   

void Inventory::add_Potions(class Potions potion, int amount){
    
    if (Potions.find(potion) != Potions.end()){
        Potions[potion] += amount;
    } else {
        Potions[potion] = amount;
    }
    
};

void Inventory::add_Weapons(class Weapons weapon, int amount){
    for(int i = 0; i < amount; i++){
        Weapons.push_back(weapon);
    }
};