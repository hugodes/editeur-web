/**
 * @file noeud.cc
 * @author Ahmed Rafik
 * @class Noeud
 * @details Surcharge des operateurs << & ==
 */

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
  father.ajoutfils(this);
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

void Noeud::ajoutfils(Noeud* N){
  (*N).setPere(this);
  (*N).setIndent(indentation + 1);
  descendant.push_back(*N);
  cout<< (*N).getPere().getNom() << " pere de " << (*N).getNom() << endl;
  /* for (list<Noeud>::const_iterator it = descendant.begin() ; it != descendant.end(); ++it){
    cout << (*it).getNom() << endl;
    }*/
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
	cout << (*it).nom << endl;
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


  /* Méthode d'accès au fils */

list<Noeud> Noeud::retournerNodesFils(){
  // cout << "nb fils = " << descendant.size() << endl;
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
