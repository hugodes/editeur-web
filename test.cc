//createur Hugo des Longchamps
#include <iostream>
#include <cstring>
using namespace std;

//#include "buffer.h"
#include "facteur.h"

int main(){
    //ecrire vos tests ici
    //Creation d'une chaine C
    string str("UnMmot");
    char *cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());
    //Construction paramétrée de Facteur
    Facteur f(cstr);
    //Affichage de Facteur
    cout<<f<<endl;
    return 0;
}
