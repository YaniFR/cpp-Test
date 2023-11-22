#include "../../Include/Enemy/Enemy.hpp"
#include "../../Include/Enemy/Zombie.hpp"
#include "../../Include/Player.hpp"

Enemy::Enemy(std::string classe){
    Name = classe;
    Stats = Player::Enemy_map[classe].get_stats();


};

Enemy::Enemy(){};