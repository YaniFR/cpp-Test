#pragma once
#include "Entity.hpp"
#include <string>
#include "Inventory.hpp"

class Player:public Entity{

    public:
        Player(std::string str);
        Player() = default;
        Inventory Inventory;   

};