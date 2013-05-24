#include <iostream>
#include <string>
#include <list>

#include "dom.h"

using namespace std;

 /* Constructeurs */ 

Dom::Dom():racine(){}

Dom::Dom(Noeud &r):racine(r){}


Dom::Dom(list<Ligne> l){
  int prof = 0;
  vector< Noeud > Arbre;
  //  cout << "test" << endl;
  if(l.empty()){
    cout << "Liste vide !!" <<endl;
  }
  else{
    for (list<Ligne>::const_iterator it = l.begin() ; it != l.end(); ++it){  
       if((*it).empty()){
	 cout << "Ligne vide !" << endl;
       }
       else{
	 for (vector<Facteur*>::const_iterator it1 = (*it).begin() ; it1 != (*it).end(); ++it1){
	   //cout << (**it1).getTexte() << " => " << (**it1).getJeton() << endl;
	   if((**it1).getJeton() == 320){
	     //cout << (**it1).getTexte() << endl;
	     string nomNoeud = (**it1).getTexte();
	     Facteur fact = (**it1);
	     Noeud N(nomNoeud, prof , fact, fact);
	     Arbre.push_back(N);
	     prof++;
	   }
	   else if((**it1).getJeton() == 331){
	     //cout << (**it1).getTexte() << endl;
	     string s=(**it1).getTexte();
	     do{
	       ++it1;
	       s += (**it1).getTexte();
	     }while((**it1).getJeton() != 332);
	     
	     char * stmp = new char[s.size() + 1];
	     copy(s.begin(), s.end(), stmp);
	     stmp[s.size()] = '\0';
	     int balisejeton = 320;

	     Facteur F(stmp, balisejeton);
	     string nomNoeud = F.getTexte();	     
	     Noeud N(nomNoeud, prof , F, F);
	     Arbre.push_back(N);
	     prof++;
	   } 
	   else if((**it1).getJeton() == 325){
	     prof--;
	   }
	   //   else cout << "text" <<endl;
	 }
       }
    }
    //  cout << "fin list" << endl;
    /*   for(vector<Noeud >::const_iterator it = Arbre.begin()++ ; it != Arbre.end(); ++it){
      cout << (*it).getNom() << " => " << (*it).getIndent() << endl;
      }
    */
    Noeud R(*Arbre.begin());
    R.setPere(R);
    racine = R;
    int j=0;
    /* cout << " racine : " << endl;
       cout << racine << endl;*/
     for(vector<Noeud>::const_iterator it = Arbre.begin()+1 ; it != Arbre.end(); ++it){
     
       cout << (*it).getNom() << endl;
       if((*it).getIndent() == 1){
	 Noeud N(*it);
	 cout << N.getNom() << endl;
	 racine.ajoutfils(N);
	 cout << N.getNom()<< " => " << N.getPere() << endl;
	 N.ajoutFils(Arbre, j);
       }
       else if((*it).getIndent()== 0){
	 while(it != Arbre.end()){
	   ++it;
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
