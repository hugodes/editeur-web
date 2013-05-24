#include <iostream>
#include <map>
#include <typeinfo>

#include "../../headers/core/noeud.h"

using namespace std;


 /* Constructeurs */ 
Noeud::Noeud(){
  nom= "noeud inconnu";
  indentation = 0;
  pere = NULL;
  facteurDeb = NULL;
  facteurFin = NULL;
}

Noeud::Noeud(string& name, int ind, Facteur &FD,  Facteur &FF){
  nom= name;
  indentation = ind;
  facteurDeb = &FD;
  facteurFin = &FF;
}

Noeud::Noeud(string& name, int ind, Noeud &father, Facteur &FD,  Facteur &FF){
  nom= name;
  indentation = ind;
  father.ajoutfils(*this);
  facteurDeb = &FD;
  facteurFin = &FF;
}

Noeud::Noeud(const Noeud& noeudcopie){
  nom= noeudcopie.nom;
  indentation = noeudcopie.indentation;
  pere = noeudcopie.pere;
  facteurDeb = noeudcopie.facteurDeb;
  facteurFin = noeudcopie.facteurFin;
}

		     
  /* Destructeur */

Noeud::~Noeud(){}

  /* Accesseurs */

string Noeud::getNom() const{
  return nom;
}

void Noeud::setNom(string _nom){
  nom = _nom;
}

Noeud Noeud::getPere() const{
    if(pere){
          return *pere;
    }
    else{
        cout<<"Pas de pere"<<endl;
    }
}

void Noeud::setPere(Noeud* N){
  pere = N;
}

int Noeud::getIndent() const{
  return indentation;
}

void Noeud::setIndent(int i){
  indentation = i;
}

Facteur* Noeud::getFacteurDeb() const{
  return facteurDeb;
}

void Noeud::setFacteurDeb(Facteur FD){
  facteurDeb = &FD;
}

Facteur* Noeud::getFacteurFin() const{
  return facteurFin;
}

void Noeud::setFacteurFin(Facteur FF){
  facteurFin = &FF;
}


  /* Méthodes pour modifier le noeud */

void Noeud::ajoutAttribut(string att){
  listeAttributs.push_back(att);
}

void Noeud::ajoutfils(Noeud N){
  descendant.push_back(N);
  N.setPere(this);
  N.setIndent(indentation + 1);
  cout<< N.getPere().getNom() << " pere de " << N.getNom() << endl;
}

/*void Noeud::ajoutFils(vector< Noeud >& arbre){
  //  cout << "test ajout" << endl;
  // cout << "je suis là" << endl;
    if(arbre.size() > 2){
      for(vector<Noeud>::const_iterator it = arbre.begin()+1 ; it != arbre.end(); it++){
	cout << (*it).getNom() << " => " << (*it).getIndent() << endl;
	cout << "Noeud courant : " << (*this).getNom() << endl;
	if((*it).getIndent() == indentation + 1){
	  cout << "je suis là" << (*it).getNom() << " => " << (*it).getIndent() << endl;
	  ajoutfils(*it);
	  if(arbre.size() > 2){
	    vector<Noeud>arbrecpy;
	    Noeud N = (*it);
	    for(vector<Noeud>::const_iterator it1 = it ; it1 != arbre.end(); ++it1){
	      arbrecpy.push_back(*it);
	      ++it;
	    }
	    for(vector<Noeud>::const_iterator it = arbre.begin() ; it != arbre.end(); ++it){
	      cout << (*it).getNom() << "\t";
	    }
	    cout << endl;
	    for(vector<Noeud>::const_iterator it1 = arbrecpy.begin() ; it1 != arbrecpy.end(); ++it1){
	      cout << (*it1).getNom() << "\t";
	    }
	    cout << endl;
	    N.ajoutFils(arbrecpy);
	  }
	}
	else if((*it).getIndent()== indentation){
	  while(it != arbre.end()){
	    ++it;
	    }
	}
      }
    }
    else cout << " arbre vide" << endl;


  if(!arbre.empty()){
     for(vector<Noeud>::const_iterator it = arbre.begin() ; it != arbre.end(); it++){
        for(vector<Noeud>::const_iterator it1 = it ; it1 != arbre.end(); it1++){
	  if((*it1).getIndent() == indentation + 1){
	    (*it).ajoutfils(*it1);
	  }
	  else if((*it1).getIndent() == indentation + 1){
	    while(it1!=arbre.end()){
	      it1++;
	    }
	  }
	  else
}*/

bool Noeud::presentfils(const Noeud& N) const{   
  if(descendant.empty()){
    return false;
  }
  else{
    list<Noeud>::const_iterator it = descendant.begin();
    while(it != descendant.end()){
      if((*it) == N){
	return true;
      }
      it++;
    }
    for (list<Noeud>::const_iterator it = descendant.begin() ; it != descendant.end(); ++it){  
      if((*it).presentfils(N)){
	return true;
      }
    }
  }
  return false;
}

bool Noeud::supprimeAttribut(string &att){
   for (list<string>::iterator it = listeAttributs.begin() ; it != listeAttributs.end(); ++it){
     if((*it) == att){
       listeAttributs.erase(it);
       return true;
     }
   }
   return false;
}

  /* Méthode d'affichage */
//  virtual istream& saisie(istream&);
 
ostream& Noeud::affiche(ostream &os) const{
  for(int i =0 ; i < indentation ; i++){
    os << '\t';
  }
  os << nom << endl;
  if(!descendant.empty()){
    for (list<Noeud>::const_iterator it = descendant.begin() ; it != descendant.end(); ++it){
      (*it).affiche(os);
    }
  }
  return os;
}

  /* Méthode de calcul */

int Noeud::nbAttribut() const{
  if(listeAttributs.empty()){
    return 0;
  }
  return listeAttributs.size();
}

int Noeud::nbFils() const{
  if(descendant.empty()){
    return 0;
  }
  return descendant.size();
}

int Noeud::indent() const{
  return indentation;
}

  /* Méthode d'accès au fils */

list<Noeud> Noeud::retournerNodesFils(){
  return descendant;
}

list<Noeud> Noeud::retournerTextFils(){
  list<Noeud> textfils;
  for (list<Noeud>::const_iterator it = descendant.begin() ; it != descendant.end(); ++it){
    if(typeid(*it).name() == "DOMText"){
       textfils.push_back(*it);
    }
  }
  return textfils;
  }

  /* Surcharge d'opérateur */

bool Noeud::operator==(const Noeud &N) const{
  if(nom == N.nom && indentation == N.indentation && pere == N.pere && facteurDeb == N.facteurDeb && facteurFin == N.facteurFin){
    if(descendant.size() == N.descendant.size()){
      list<Noeud>::const_iterator itN = N.descendant.begin();
      for (list<Noeud>::const_iterator it = descendant.begin() ; it != descendant.end(); ++it){
	if(it == itN){
	  ++itN;
	}
	else return false;
      }
    }
    if(listeAttributs.size() == N.listeAttributs.size()){
      list<string>::const_iterator itN1 = N.listeAttributs.begin();
      for (list<string>::const_iterator it1 = listeAttributs.begin() ; it1 != listeAttributs.end(); ++it1){
	if(it1 == itN1){
	  ++itN1;
	}
	else return false;
      }
    }
      return true;
  }
  return false;
}
  

/* Surcharge de Flots */
ostream& operator<< (ostream &os, const Noeud &node){
  node.affiche(os);
  return os;
}

//istream& operator>> (istream&, Noeud&);
