#pragma once
#include <istream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>
#include "Potions.hpp"
#include <iostream>

class Inventory{
    private:
        std::vector<Potions> Potions;

    public:
        Inventory(){
            Potions.push_back(small_Potion());
        };

        friend std::ostream& operator<<(std::ostream& os,class Inventory& Inventory){
            for(class Potions &potion : Inventory.Potions){
                os << potion.Name << std::endl;
            }
            return os;
        };

        void add_Potions(class Potions potion){
            Potions.push_back(potion);
        }

};