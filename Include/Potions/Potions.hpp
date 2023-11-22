#pragma once
#include <string>

class Potions{

    public:
        Potions();

        bool operator<(const Potions& other) const;
        std::string get_name() const;
    
    protected:

        std::string Name;
        size_t Value;
};
