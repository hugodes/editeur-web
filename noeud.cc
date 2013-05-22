#include <iostream>
#include <map>
#include <typeinfo>

#include "noeud.h"
//#include "noeudtexte.h"

using namespace std;


 /* Constructeurs */ 
Noeud::Noeud(){
  nom= "noeud inconnu";
  indentation = 0;
  pere = NULL;
  /*  lignedeb = NULL;
      lignefin = NULL;*/
  facteurDeb = NULL;
  facteurFin = NULL;
}

Noeud::Noeud(string& name, int ind, Noeud &father, Facteur &FD,  Facteur &FF){
  nom= name;
  indentation = ind;
  pere = &father;
  /*  lignedeb = &LD;
      lignefin = &LF;*/
  facteurDeb = &FD;
  facteurFin = &FF;
}

Noeud::Noeud(const Noeud& noeudcopie){
  nom= noeudcopie.nom;
  indentation = noeudcopie.indentation;
  pere = noeudcopie.pere;
  /*  lignedeb = noeudcopie.lignedeb;
      lignefin = noeudcopie.lignefin;*/
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
  return *pere;
}

void Noeud::setPere(Noeud N){
  pere = &N;
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
  N.setPere(*this);
  N.setIndent(indentation + 1);
}

void Noeud::ajoutFils(Noeud N, vector< pair<Facteur, int> > arbre, int j){
  ajoutfils(N);
  int prof = (*(arbre.begin()+j)).second;
  for(vector< pair<Facteur, int> >::const_iterator it = arbre.begin()+j ; it != arbre.end(); ++it){
      while((*it).second > prof){
	if((*it).second == prof + 1){
	  string nomNoeud = (*it).first.getTexte();
	  Facteur fact = (*it).first;
	  Noeud N(nomNoeud, indentation+1, (*this), fact, fact);
	  (*this).ajoutFils(N, arbre, j);
	}
      }
      j++;
  }
} 

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
