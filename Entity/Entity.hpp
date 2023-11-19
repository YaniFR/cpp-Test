#include <string>

class Entity {
public : 

    Entity(double x, std::string str);
    Entity();

    double HP {0.0};

    std::string Name = "Default";


private : 

    double remaining_HP(double &HP, double damage);

};