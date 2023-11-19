#include <iostream>
#include <ostream>
#include <vector>
#include <map>
#include "json.hpp"
#include <fstream>
#include <sstream>
#include "./Include/Entity.hpp"
#include "./Include/Player.hpp"
using json = nlohmann::json;
using namespace std;

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
            Player Potbuy("Potbuy");
            cout << Potbuy.get_name() << endl;
            cout << Potbuy.get_value("HP") << endl;
            Potbuy.Inventory.print();

            
        }
        // default : 
        default : {
            auto dz = []()->string{ return "tahia rajel djazair"; }; // lambda function
        }
    
    }
    return 0;
}