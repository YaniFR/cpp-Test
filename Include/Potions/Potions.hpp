#pragma once
#include <string>

class Potions{

    public:
        Potions();
        std::string Name;
        size_t Value;

        bool operator<(const Potions& other) const {
        // Implémentez votre logique de comparaison ici
        // Par exemple, si vous avez un attribut name représentant le nom de la potion :
            return Name < other.Name;
        };
    
        
};
