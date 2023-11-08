#include <iostream>
#include <vector>
using namespace std;

vector<string> get_strings(string caca1){

    // création d'un tableau
    vector< string > liste_de_caca; 
    
    // réservation de 2 places maximum pour le tableau
    liste_de_caca.reserve(2); 

    string caca = "mortier au caca";

    // equivalent de append
    liste_de_caca.push_back(caca); 
    liste_de_caca.push_back(caca1);

    return liste_de_caca;
}

const int potbuy = 1;
const int noven = 2;
const int yani = 3;

string personnage(int personnage){

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

int main(int argc,string argv ){

    short unsigned int pos {8}; // 2 bytes, valeur seulement positif grace au unsigned
    auto pos2 {8u}; // determine automatiquement unsigned int 
    short signed int neg {-12}; // 2 bytes, valeur acceptant les nombres négatifs grace au signed

    vector<string> texte = get_strings(argv);
    cout << texte[0] << pos << endl;        
    cout << texte[1] << neg << endl;
    cout << texte.size() << std::endl;
    
    return 0;
}