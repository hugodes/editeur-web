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
  
    //Construction par copie
    Facteur f11(f1);
    
    //Changer le texte du Facteur
    str = ("UnMot");
    char *cstr1 = new char[str.length()+1];
    strcpy(cstr1, str.c_str());
    f11.setTexte(cstr1);
    delete cstr1;

    //Recuperer le texte du Facteur
    cout << "Le texte du facteur est: " << endl;
    cout << f11.getTexte() << endl ;
    
    //Changer la couleur du Facteur
    str = ("#FFF000");
    char *cstr2 = new char[str.length()+1];
    strcpy(cstr2, str.c_str());
    f11.setCouleur(cstr2);
    delete cstr2;

    //Recuperer le texte formate du facteur
    cout << "Le texte formate du facteur est: " << endl;
    cout << f11.getTexteFormate() << endl;

    //Affichage de Facteur
    cout<<"Affichage d'un facteur:"<<endl;
    cout<<f1<<endl;
    
    //Affichage de Facteur
    cout<<"Affichage d'un facteur:"<<endl;
    cout<<f11<<endl;

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
