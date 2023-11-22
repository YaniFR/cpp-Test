#include "../../Include/Potions/Potions.hpp"
#include "../../Include/Inventory.hpp"

Potions::Potions(){};

bool Potions::operator<(const Potions& other) const {
    return Name < other.Name;
};

std::string Potions::get_name() const{
    return Name;
};
