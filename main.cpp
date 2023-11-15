#include <iostream>
#include <vector>
#include <map>
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;
using namespace std;

vector<char *> get_strings(char *caca1){

    // création d'un tableau
    vector<char *> liste_de_caca; 
    
    // réservation de 2 places maximum pour le tableau
    liste_de_caca.reserve(2); 

    char caca[16] = "mortier au caca";

    // equivalent de append
    liste_de_caca.push_back(caca); 
    liste_de_caca.push_back(caca1);

    return liste_de_caca;
}

const int potbuy = 1;
const int noven = 2;
const int yani = 3;
const char *caca = "dz";

//perso.push_back("dz");


void personnage(vector<string> personnage){
    
    

    int i;
    for(i = 0; i < personnage.size(); i++){
        cout << personnage[i] << endl;
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

map<string, unsigned short int> dictio;

void initialize_map(){
    ifstream fichier_poids("poids.json");
    json data = json::parse(fichier_poids); 
    
    dictio = data["KEY"]; 
    //cout << data["KEY"];
}


bool dans_dictio(string perso){

    return dictio.count(perso);

}
string leplusgros(vector<string> perso){
    /*unsigned short int cocoloco = 600;
    unsigned short int dahmen = 2;*/

    if (dans_dictio(perso[0]) && dans_dictio(perso[1])){
        string legros = (dictio[perso[0]] < dictio[perso[1]]) ?  perso[1] : perso[0];
        return legros;
    }
    else{
        return "Le personnage ne figure pas dans le dictionnaire";
    }
}

int main(int argc,char **argv){

    switch(atoi(argv[1])){
        
        // 1 : retourne la liste des personnages
        case 1: {   
            vector<string> perso(argv + 2, argv + argc);
            //perso.assign(argv + 1, argv + argc);
            vector<string> perso2;
            perso2.insert(perso2.end(), {"potbuy","yani","noven","issuko","kamaboko"});
            personnage(perso);
        }

        // 2 : test random osef
        case 2: {
            short unsigned int pos {8}; // 2 bytes, valeur seulement positif grace au unsigned
            auto pos2 {8u}; // determine automatiquement unsigned int 
            short signed int neg {-12}; // 2 bytes, valeur acceptant les nombres négatifs grace au signed

            /*vector<char *> texte = get_strings(argv[1]);
            cout << texte[0] << endl << pos << endl;        
            cout << texte[1] << endl << neg << endl;*/
            cout << argc << endl;
            //cout << texte.size() << std::endl; 
        }

        // 3 : test de la fonction le plus gros >>> n'utilise que les deux premiers arguments
        case 3: {
            initialize_map();
            vector<string> perso(argv + 2, argv + 4);
            cout << leplusgros(perso);
        }

        case 4: {
            initialize_map();
        }
    
    }
    return 0;
}