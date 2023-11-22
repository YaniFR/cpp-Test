#pragma once
#include "Entity.hpp"
#include <string>
#include "Inventory.hpp"
#include "./Classes/Classes.hpp"

class Player:public Entity{

    public:
        Player(std::string str);

        Inventory Inventory;
        Classes Classe;

        void set_stats(class Classes Classe);
        void set_classe(std::string classe);
        bool classe_exists(std::string classe);
        class_map Classes_map;

    protected:
        void init_class();
};