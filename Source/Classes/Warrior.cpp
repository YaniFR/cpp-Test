#include "../../include/Classes/Warrior.hpp"
#include <string>

Warrior::Warrior(){
    Name = "Warrior";
    Stats = {
        {"HP", 100}, // Vie
        {"MP", 20}, // Mana
        {"ATK", 80}, // Attaque
        {"DEF", 50}, // Defense
        {"SPE", 30}, // Speed
        {"LCK", 2} // Chance
    };
};
