#pragma once
#include <string>
#include <map>

typedef std::map<std::string, size_t> t_map;

class Entity {

public: 

    Entity(t_map map, std::string str);
    Entity() = default;

    // getters
    void remaining_HP(size_t damage);
    void stats_change(std::string stat, int change);

    // setters
    size_t get_stat(std::string stat);
    std::string get_name();

    t_map Stats {
        {"HP", 0}, // Vie
        {"MP", 0}, // Mana
        {"ATK", 0}, // Attaque
        {"DEF", 0}, // Defense
        {"SPE", 0}, // Speed
        {"LCK", 0} // Chance
    };

protected:

    std::string Name = "Default";

};