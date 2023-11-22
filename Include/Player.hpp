#pragma once
#include "Entity.hpp"
#include <string>
#include <vector>
#include "Inventory.hpp"
#include "./Classes/Classes.hpp"

typedef std::map<std::string, class Enemy> enemy_map;

class Player:public Entity{

    public:
        Player(std::string str);

        Inventory Inventory;
        Classes Classe;

        void set_stats(class Classes Classe);
        void set_classe(std::string classe);

        std::vector<std::string> get_Classes();
        bool classe_exists(std::string classe);

        class_map Classes_map;
        static enemy_map Enemy_map;


    protected:
        void init_class();
        void init_enemy();
};