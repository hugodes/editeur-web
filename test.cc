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
#include "dom.h"

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

     /*********************/
    /*  Test sur Noeud   */
   /*********************/

    /* Création de facteurs */

    Facteur F0("hello");
    Facteur F1("world");
    Facteur F2("<html>");
    Facteur F3("<body>");
    Facteur F4("Ceci");
    Facteur F5("est");
    Facteur F6("mon");
    Facteur F7("site");
    Facteur F8("trop");
    Facteur F9("genial");

    /* Vecteur de facteur */

    vector<Facteur>V0;
    vector<Facteur>V1;
    vector<Facteur>V2;
    vector<Facteur>V3;
    vector<Facteur>V4;

    /* Initialisation des vecteurs de facteurs */

    V0.push_back(F0);
    V0.push_back(F1);
    V1.push_back(F2);
    V2.push_back(F3);
    V3.push_back(F4);
    V3.push_back(F5);
    V4.push_back(F6);
    V4.push_back(F7);
    V4.push_back(F8);
    V4.push_back(F9);

    /* Création de lignes */ 
    
    Ligne L0(V1);
    Ligne L1(V2);
    Ligne L2(V0);
    Ligne L3(V3);
    Ligne L4(V4);

    /* Création de Noeud */

    Noeud N1();
    Noeud N2("<p1>", 3, N1, L2, L2, F0, F1);
    Noeud N3("<p2>", 3, N1, L3, L4, F4, F9);
    Noeud N4("html", 0, N4, L0, L0, F2, F2);
    Noeud N5();

    /* Initialisation de N1 */

    N1.setNom("<body>");
    N1.setIndent(1);
    N1.setPere(N4);
    N1.setLigneDeb(L1);
    N1.setLigneFin(L1);
    N1.setFacteurDeb(F3);
    N1.setFacteurFin(F3);

    /* Création d'un DOM */

    Dom D(N4);

    cout << D << endl;

    /* Modification du DOM */

    D.ajoutNoeud(N2, N5);

    cout << D << endl;
    
    /* Calcul sur Noeud */
    
    cout << "Le noeud N1 a " << N1.nbFils() << " fils," << endl;
    cout << " et est indenté de " << N1.indent() << endl;

    


    return 0;
}
