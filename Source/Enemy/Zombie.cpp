#include "../../Include/Enemy/Zombie.hpp"

Zombie::Zombie(){
    Name = "Zombie";
    Stats = {
        {"HP", 100},
        {"MP", 0},
        {"ATK", 10},
        {"DEF", 10},
        {"SPD", 10},
        {"LCK", 0}
    };
}