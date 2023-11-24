#include <algorithm>
#include <corecrt.h>
#include <iostream>
#include <ostream>
#include <vector>
#include <map>
#include "Warrior.hpp"
#include "json.hpp"
#include <fstream>
#include <sstream>
#include "./Include/Player.hpp"
#include "./Include/Classes/Classes.hpp"
#include "./Include/Enemy/Enemy.hpp"
using json = nlohmann::json;
using namespace std;
using t_map = std::map<std::string, double>;

vector<string> get_strings(string caca1){

    // création d'un tableau
    vector<string> liste_de_caca; 
    
    // réservation de 2 places maximum pour le tableau
    liste_de_caca.reserve(2); 

    string caca = "mortier au caca";

    // equivalent de append
    liste_de_caca.push_back(caca); 
    liste_de_caca.push_back(caca1);

    return liste_de_caca;
}
typedef short unsigned int dz;

const dz potbuy = 1;
const dz noven = 2;
const dz yani = 3;
const string caca = "dz";

//perso.push_back("dz");

void personnage(vector<string> personnage){
    
    
    for(string &perso : personnage){
        perso += " caca";
        cout << perso << endl;
    }
}

string personnagetest(int personnage){

    switch (personnage){
        case potbuy: {
            return "potbuy";
        }
        case noven: {
            return "noven";
        }
        case yani: {
            return "yani";
        }
        default: {
            return "personnage non valide";
        }
    }

}

//typedef map<string, unsigned short int> t_map;

void initialize_map(t_map &dictio){

    ifstream fichier_poids("poids.json");
    json data = json::parse(fichier_poids); 
    
    dictio = data["KEY"]; 
    //cout << data["KEY"];
}



bool dans_dictio(string perso, t_map &dictio){
    
    return dictio.count(perso);

}
string leplusgros(vector<string> perso, t_map &dictio){
    /*unsigned short int cocoloco = 600;
    unsigned short int dahmen = 2;*/

    if (dans_dictio(perso[0], dictio) && dans_dictio(perso[1], dictio)){
        string legros = (dictio[perso[0]] < dictio[perso[1]]) ?  perso[1] : perso[0];
        return legros;
    }
    else{
        return "Le personnage ne figure pas dans le dictionnaire";
    }
}

string liste_perso(t_map &dictio){
    ostringstream liste;
    for( const auto &[key, valeur] : dictio){
        liste << key << " : " << valeur << "\n";
    }
    return liste.str();
}


template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const map<K,V>& map) {
    for (const auto& pair : map) {
        os << pair.first << ": " << pair.second << endl;
    }
    return os;
};

template<typename K>
std::ostream& operator<<(std::ostream& os, const vector<K>& vector) {
    for (const auto& pair : vector) {
        os << pair << endl;
    }
    return os;
};

void app();

void init();

void action(string action, class Player &player, bool &game, class Enemy &Enemy);

void inventory(class Player &player);

void quit(bool &game);

void attack(class Player &player, class Enemy &enemy);


int main(int argc,char **argv){

    switch(atoi(argv[1])){
        
        // 1 : retourne la liste des personnages
        case 1: {   
            vector<string> perso(argv + 2, argv + argc);
            //perso.assign(argv + 1, argv + argc);
            //vector<string> perso2;
            //perso2.insert(perso2.end(), {"potbuy","yani","noven","issuko","kamaboko"});
            personnage(perso);
        }

        // 2 : test random osef
        case 2: {
            short unsigned int pos {8}; // 2 bytes, valeur seulement positif grace au unsigned
            auto pos2 {8u}; // determine automatiquement unsigned int 
            short signed int neg {-12}; // 2 bytes, valeur acceptant les nombres négatifs grace au signed

            /*vector<string> texte = get_strings(argv[1]);
            cout << texte[0] << endl << pos << endl;        
            cout << texte[1] << endl << neg << endl;*/
            cout << argc << endl;
            //cout << texte.size() << std::endl; 
        }

        // 3 : test de la fonction le plus gros >>> n'utilise que les deux premiers arguments
        case 3: {
            t_map dictio;
            initialize_map(dictio);
            vector<string> perso(argv + 2, argv + 3);
            cout << leplusgros(perso, dictio);
        }

        // 4 : test dictio
        case 4: {
            t_map dictio;
            initialize_map(dictio);
        }

        // 5 : liste tout les personnages disponnibles
        case 5: {
            t_map dictio;
            initialize_map(dictio);
            cout << liste_perso(dictio);
        }
        // test des class
        case 6: {
            //Entity Zombie(10.0, "Zombie");
            //Entity Zebi;
            /*cout << Zombie << endl << Zombie.Name << endl;
            cout << Zebi.Name;*/
            //Warrior dz;
            //Player Potbuy("Potbuy");
            /*cout << Potbuy.Classes_map["Warrior"].get_name() << endl;
            cout << Potbuy.Classes_map["Warrior"].get_Stats()<< endl;
            Potbuy.set_classe("Warrior");
            //cout << Potbuy.get_stat("HP") << endl;
            cout << Potbuy.get_name() << endl;
            cout << Potbuy.Classe.get_name() << endl;
            cout << Potbuy.Classe.get_Stats() << endl;
            Potbuy.Inventory.print();*/
            /*Enemy Zombie("Zombie");
            cout << Zombie.get_name() << endl;
            cout << Zombie.get_stats() << endl;*/

            
        }
        // default : 
        default : {
            init();
            //auto dz = []()->string{ return "tahia rajel djazair"; }; // lambda function
        }
    
    }
    return 0;
}

void app(){
    init();
    /*vector<string> valid_action = {"inventory", "quit"};
    string action;
    while(find(valid_action.begin(), valid_action.end(), action) != valid_action.end()){
        cout << "What do you want to do ?" << endl;
        cout << "Available action are : inventory, stats, quit" << endl;
        cin >> action;
    }*/
};

void action(string action, class Player &player, bool &game, class Enemy &Enemy){
    if(action == "inventory"){
        inventory(player);
    }
    else if(action == "quit"){
        quit(game);
    }
    else if(action == "attack"){
        attack(player, Enemy);
    }
    else{
        cout << "Invalid action, please choose a valid action : ";
    }


};

void inventory(class Player &player){
    player.Inventory.print();
};

void quit(bool &game){
    game = false;
    cout << "Thanks for playing !" << endl;
};

void attack(class Player &player, class Enemy &enemy){
    size_t damage = player.get_stat("ATK")/10 - enemy.get_stat("DEF")/5;
    if(damage < 0){
        damage = 0;
    };
    enemy.remaining_HP(damage);
    cout << "You attack " << enemy.get_name() << " and deal " << damage << " damage" << endl;
};

void init(){
    cout << "Welcome to the game !" << endl;
    cout << "Choose a name for your character : ";
    string name;
    cin >> name;
    Player player(name);
    cout << "Choose a class for your character, available class are : " << endl << player.get_Classes() << endl;
    string classe;
    bool valid_classe = false;
    while(!valid_classe){
        cin >> classe;
        if(player.Classes_map.count(classe)){
            valid_classe = true;
            player.set_classe(classe);
        }
        else{
            cout << "Invalid class, please choose a valid class : ";
        }
    }
    cout << "You choose " << player.get_name() << " as name and " << player.Classe.get_name() << " as class" << endl;
    Enemy Zombie("Zombie");
    bool game = true;
    while(game){
        cout << "Your HP : " << player.get_health() << endl;
        cout << "Enemy HP : " << Zombie.get_health() << endl;
        cout << "What do you want to do ?" << endl;
        cout << "Available action are : attack, inventory, quit" << endl;
        string choose_action;
        while (choose_action != "attack" && choose_action != "inventory" && choose_action != "quit") {
            cin >> choose_action;
            action(choose_action, player, game, Zombie);
            if (Zombie.get_status() == "Dead") {
                cout << "You killed the Zombie !" << endl;
                game = false;
            }
        }
    };

};
