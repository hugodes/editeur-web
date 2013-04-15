#include <iostream>
#include <string>
#include <list>
#include <map>

#include "dom.h"

using namespace std;

 /* Constructeurs */ 

Dom::Dom():racine(){}

Dom::Dom(Noeud &r):racine(r){}
  
  /* Destructeur */
  
Dom::~Dom(){}

  /* Méthodes pour modifier le DOM */

bool Dom::ajoutNoeud(Noeud pere, Noeud fils){
  if(noeudPresent(pere)){
    pere.ajoutfils(fils);
    return true;
  }
  else{
    cout << "Le noeud père ne fait pas partie de DOM!!" << endl;
    return false;
  }
}

/*
bool Dom::supprimeNoeud(Noeud& n){
  if(n == racine){
    Noeud n1();
    n1 = racine.
  }
}
*/

bool Dom::noeudPresent(const Noeud N){
  if(N == racine){
    return true;
  }
  else{
    return racine.presentfils(N); 
  }
}

  /* Méthode d'affichage */

ostream& Dom::affiche(ostream &os) const{
  os << racine.affiche(os);
  return os;
}

  /* Méthode de calcul */
/*int Dom::nbNoeud() const{
  return 1 + racine.nbFils();
}
*/
  /* méthode d'information graphique */
int Dom::retournerTabLigne(Noeud N){
  if(noeudPresent(N)){
    return N.getIndent();
  }
  else{
    cout << "Erreur : Le noeud ne fait pas partie du DOM!!" << endl;
    return -1;
  }
}
/*
Noeud Dom::retournerPtrNode(Ligne L){
  return racine.ptrNode(L);
}
*/
//int Dom::indentFormelle(Ligne &L){}
  


/* Surcharge de Flots */
ostream& operator<< (ostream& os, const Dom& dom){
  dom.affiche(os);
  return os;
}

//istream& operator>> (istream&, Dom&);
