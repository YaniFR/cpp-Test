#include <iostream>
#include <vector>
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

string leplusgros(){
    unsigned short int cocoloco = 600;
    unsigned short int dahmen = 2;

    string legros = (cocoloco < dahmen) ?  "dahmen" : "cocoloco";
    return legros;
}

int main(int argc,char **argv){

    short unsigned int pos {8}; // 2 bytes, valeur seulement positif grace au unsigned
    auto pos2 {8u}; // determine automatiquement unsigned int 
    short signed int neg {-12}; // 2 bytes, valeur acceptant les nombres négatifs grace au signed

    vector<char *> texte = get_strings(argv[1]);
    cout << texte[0] << endl << pos << endl;        
    cout << texte[1] << endl << neg << endl;
    cout << argc << endl;
    cout << texte.size() << std::endl;
    
    return 0;
}