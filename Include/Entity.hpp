#pragma once
#include <string>
#include <map>

typedef std::map<std::string, double> t_map;

class Entity {

public: 

    Entity(t_map map, std::string str);
    Entity() = default;


    void remaining_HP(double damage);
    void stats_change(std::string stat, int change);
    std::string get_status();

    t_map get_stats();
    std::string get_name();
    double get_health();
    double get_stat(std::string stat);
    void set_status(std::string str);

protected:

    std::string status = "Idle";

    std::string Name = "Default";
    t_map Stats {
        {"HP", 0}, // Vie
        {"MP", 0}, // Mana
        {"ATK", 0}, // Attaque
        {"DEF", 0}, // Defense
        {"SPE", 0}, // Speed
        {"LCK", 0} // Chance
    };

};