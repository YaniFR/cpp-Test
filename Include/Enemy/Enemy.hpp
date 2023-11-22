#pragma once
#include "../Entity.hpp"
#include <string>
#include "../Player.hpp"

using enemy_map = std::map<std::string, class Enemy>;

class Enemy:public Entity{

    public:
        Enemy(std::string str);
        Enemy();
};
