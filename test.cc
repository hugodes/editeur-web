//createur Hugo des Longchamps
#include <iostream>
#include <cstring>
using namespace std;

//#include "buffer.h"
#include "facteur.h"

int main(){
    //ecrire vos tests ici
    string str("UnMmot");
    char *cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());
    cout<<"Je suis dans le main"<<endl;
    Facteur f(cstr);
    cout<<"Voici ce qu'affiche f"<<endl;
    cout<<f<<endl;
    return 0;
}
