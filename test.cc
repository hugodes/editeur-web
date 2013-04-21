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
#include "noeudtexte.h"
#include "buffer.h"

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
    cout<<"Affichage de facteur"<<endl<<"----------------------------------"<<endl;
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
    cout<<f11<<endl<<endl<<endl;

    //******************
    //Tests sur Ligne
    //******************

    //Creation d'une deuxième chaîne C
    str="\t";
    cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());
      	
    //Construction d'un deuxième facteur
    Facteur f2(cstr);
    delete cstr;
    
    //Creation d'une troisieme chaîne 
    str="DeuMot";
    cstr= new char[str.length()+1];
    strcpy(cstr, str.c_str());
    
    //Construction d'un troisième facteur
    Facteur f3(cstr);
    delete cstr;

    str=" ";	
    cstr= new char[str.length()+1];
    strcpy(cstr, str.c_str());
    
    Facteur f4(cstr);
    delete cstr;

    //Creation d'un vecteur de facteurs
    vector<Facteur> v1;
    v1.push_back(f2);   //tabulation
    v1.push_back(f2);	//tabulation
    v1.push_back(f3);  
    v1.push_back(f4);   //espace
    v1.push_back(f1);

    //Construction d'une ligne
    Ligne l1(v1);

    //Affichage d'une ligne 
    cout<<"Affichage de Ligne"<<endl<<"------------------------------"<<endl;
    cout<<"la ligne ainsi l'indentation(s) : \n";
    cout<<l1<<endl<<endl<<endl;



    //*****************
    //Tests sur Buffer
    //*****************

    //Constructeur par défaut
    Buffer b1;
    //Affichage
    cout<<"Affichage de Buffer"<<endl<<"------------------------------"<<endl;
    cout<<"Affichage du premier buffer:"<<endl;
    cout<<b1<<endl;

    //Constructeur paramétré avec le chemin vers un fichier
    string str3("testinput.txt");
    char *cstr3 = new char[str3.length()+1];
    strcpy(cstr3, str3.c_str());
    Buffer b2(cstr3);
    cout<<"Affichage du deuxième buffer:"<<endl;
    cout<<b2<<endl;

    //Ajout d'une ligne

    //getDom
    //b1.getDom();

    //setDom
    /*Ne marche pas pour l'instant
    b1.setDom(D);
    */

    //getLigne
//    b1.getLignes();

    //setLignes

     /*********************/
    /*  Test sur Noeud   */
   /*********************/

    /* Création de facteurs */

    /* Mise en commentaire car les tests ne marchent pas
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
    fin du commentaire temporaire*/

    /* Vecteur de facteur */

    /* Mise en commentaire car les tests ne marchent pas
    vector<Facteur>V0;
    vector<Facteur>V1;
    vector<Facteur>V2;
    vector<Facteur>V3;
    vector<Facteur>V4;
    fin du commentaire temporaire*/

    /* Initialisation des vecteurs de facteurs */

    /* Mise en commentaire car les tests ne marchent pas
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
    fin du commentaire temporaire*/

    /* Création de lignes */ 
    
    /* Mise en commentaire car les tests ne marchent pas
    Ligne L0(V1);
    Ligne L1(V2);
    Ligne L2(V0);
    Ligne L3(V3);
    Ligne L4(V4);
    fin du commentaire temporaire*/

    /* Création de Noeud */

    /* Mise en commentaire car les tests ne marchent pas
    Noeud N1();
    Noeud N2("<p1>", 3, N1, L2, L2, F0, F1);
    Noeud N3("<p2>", 3, N1, L3, L4, F4, F9);
    Noeud N4("html", 0, N4, L0, L0, F2, F2);
    Noeud N5();
    fin du commentaire temporaire*/

    /* Initialisation de N1 */

    /* Mise en commentaire car les tests ne marchent pas
    N1.setNom("<body>");
    N1.setIndent(1);
    N1.setPere(N4);
    N1.setLigneDeb(L1);
    N1.setLigneFin(L1);
    N1.setFacteurDeb(F3);
    N1.setFacteurFin(F3);
    fin du commentaire temporaire*/

    /* Création d'un DOM */

    /* Mise en commentaire car les tests ne marchent pas
    Dom D(N4);

    cout << D << endl;
    fin du commentaire temporaire*/

    /* Modification du DOM */

    /* Mise en commentaire car les tests ne marchent pas
    D.ajoutNoeud(N2, N5);

    cout << D << endl;
    fin du commentaire temporaire*/
    
    /* Calcul sur Noeud */
    
    /* Mise en commentaire car les tests ne marchent pas
    cout << "Le noeud N1 a " << N1.nbFils() << " fils," << endl;
    cout << " et est indenté de " << N1.indent() << endl;
    fin du commentaire temporaire*/




    return 0;
}
