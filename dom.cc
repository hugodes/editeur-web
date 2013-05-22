#include <iostream>
#include <string>
#include <list>
#include <map>

#include "dom.h"

using namespace std;

 /* Constructeurs */ 

Dom::Dom():racine(){}

Dom::Dom(Noeud &r):racine(r){}


Dom::Dom(list<Ligne> l){
  int prof = 0;
  vector< pair<Facteur, int> > Arbre;
  if(l.empty()){
    cout << "Liste vide !!" <<endl;
  }
  else{
     for (list<Ligne>::const_iterator it = l.begin() ; it != l.end(); ++it){  
       if((*it).empty()){
	 cout << "Ligne vide !" << endl;
       }
       else{
	 for (vector<Facteur>::const_iterator it1 = (*it).begin() ; it1 != (*it).end(); ++it1){
	   if((*it1).getJeton() == 320){
	     Arbre.push_back(make_pair((*it1),prof));
	     prof++;
	   }
	   else if((*it1).getJeton() == 331){
	     string s=(*it1).getTexte();
	     do{
	       ++it1;
	       s += (*it1).getTexte();
	     }while((*it1).getJeton() != 332);

	     Facteur F(s);
	     Arbre.push_back(make_pair(F,prof));
	     prof++;
	   } 
	   else if((*it1).getJeton() == 325){
	     prof--;
	   }
	 }
       }
     }
     
     racine = new Noeud((*Arbre.begin()).first().getTexte(), 0, NULL, (*Arbre.begin()).first(), (*Arbre.begin()).first());
     prof = 0;
     int j = 0;
     for(vector< pair<Facteur, int> >::const_iterator it = Arbre.begin()++ ; it != Arbre.end(); ++it){
	 while((*it).second() > prof){
	   if((*it).second() == prof + 1){
	     Noeud N = new Noeud((*it).first().getTexte(), 0, racine, (*it).first(), (*it).first());
	     racine.ajoutFils(N, Arbre, j);
	   }
	 }
	 j++;
       } 
  }	  
}	     
  

  
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
