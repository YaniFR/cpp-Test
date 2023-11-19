#pragma once
#include <string>

class Potions{

    public:
        Potions() = default;
        std::string Name;
        size_t Value;
        
};

class small_Potion:public Potions{
    public:
        small_Potion(){
            Name = "small_Potion";
            Value = 100;
        };
};