#include <iostream>
#include <vector>
using namespace std;

vector<string> get_strings(string caca1){
    vector< string > liste_de_caca;
    string caca = "mortier au caca";
    liste_de_caca.push_back(caca);
    liste_de_caca.push_back(caca1);
    return liste_de_caca;
}


int main(){
    vector<string> texte = get_strings("caca y dos");
    cout << texte[0] << endl;
    cout << texte[1] << endl;
    cout << texte.size() << endl;
    
    return 0;
}