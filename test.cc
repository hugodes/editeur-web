/**
 * @file test.cc
 * @author Hugo des Longchamps
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#include "facteur.h"
#include "ligne.h"

int main(){
    //*****************
    //Tests sur Facteur
    //*****************

    //Creation d'une chaine C
    string str("UnMmot");
    char *cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());

    //Construction paramétrée de Facteur
    Facteur f1(cstr);
    delete cstr;
    //Affichage de Facteur
    cout<<"Affichage d'un facteur:"<<endl;
    cout<<f1<<endl;

    //******************
    //Tests sur Ligne
    //******************

    //Creation d'une deuxième chaîne C
    str="UnDeuxièmeMot";
    cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());

    //Construction d'un deuxième facteur
    Facteur f2(cstr);
    delete cstr;

    //Creation d'un vecteur de facteurs
    vector<Facteur> v1;
    v1.push_back(f1);
    v1.push_back(f2);

    //Construction d'une ligne
    Ligne l1(v1);

    //Affichage d'une ligne
    cout<<"Affichage d'une ligne"<<endl;
    cout<<l1<<endl;

    return 0;
}
