#pragma once
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>
#include "./Potions/Potions.hpp"
#include "./Weapons/Weapons.hpp"
#include <map>
#include <algorithm>

typedef std::map<class Potions, int> Potions_map;

class Inventory{
    private:
        std::vector<Weapons> Weapons;

        int num_Potions;
        int num_Weapons;        

    public:
        Inventory();

        Potions_map Potions;

        void print();
        void add_Potions(class Potions potion, int amount = 1);
        void add_Weapons(class Weapons weapon, int amount = 1);

};