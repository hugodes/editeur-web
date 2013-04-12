#include <iostream>
#include <string>
#include <list>
#include <map>

#include "noeud.h"

using namespace std;


 /* Constructeurs */ 
Noeud::Noeud(){
  nom= "noeud inconnu";
  indentation = 0;
  pere = null;
  lignedeb = null;
  lignefin = null;
  facteurdeb = null;
  facteurfin = null;
}

Noeud::Noeud(string name, int ind, Noeud &father, Ligne &LD, Ligne &LF, Facteur &FD, Facteur &FF){
  nom= name;
  indentation = ind;
  pere = father;
  lignedeb = LD;
  lignefin = LF;
  facteurdeb = FD;
  facteurfin = FF;
}

Noeud::Noeud(const Noeud& Noeudcopie){
  nom= noeudcopie.nom;
  indentation = noeudcopie.indentation;
  pere = &noeudcopie.pere;
  lignedeb = &noeudcopie.lignedeb;
  lignefin = &noeudcopie.lignefin;
  facteurdeb = &noeudcopie.facteurdeb;
  facteurfin = &noeudcopie.facteurfin;
}
  
  /* Destructeur */

Noeud::~Noeud(){
  delete lignedeb;
  delete lignefin;
  delete facteurdeb;
  delete facteurfin;
  delete[] listeAttributs;
  delete[] descendant;
}

  /* Accesseurs */

string Noeud::getNom() const{
  return nom;
}

void Noeud::setNom(string _nom){
  nom = _nom;
}

Ligne* Noeud::getLigneDeb() const{
  return lignedeb;
}

void Noeud::setLigneDeb(Ligne& LD){
  lignedeb = LD;
}

Ligne* Noeud::getLigneFin() const{
  return lignefin;
}

void Noeud::setLigneFin(Ligne& LF){
  lignefin = LF;
}

Facteur* Noeud::getFacteurDeb() const{
  return facteurdeb;
}

void Noeud::setFacteurDeb(Facteur& FD){
  facteurdeb = FD;
}

Facteur* Noeud::getFacteurFin() const{
  return facteurfin;
}

void Noeud::setFacteurfin(Facteur& FF){
  facteurfin = FF;
}

  /* Méthodes pour modifier le noeud */

void Noeud::ajoutAttribut(String att){
  if(listeAttributs == null){
    listeAttributs();
  }
  listeAttributs.push_back(&att);
}

void Noeud::ajoutfils(const Noeud &N){
   if(descendant == null){
    descendant();
  }
  descendant.push_back(&N);
  N.pere = this;
  N.indentation = indentation + 1;
}

bool Noeud::presentfils(const Noeud& N) const{    // vérifie si un noeud est présent dans la liste des fils du noeud courant
  if(descendant == null){
    return false;
  }
  else{
    for (Noeud::iterator it = descendant.begin() ; it != descendant.end(); ++it){
      if(*it == N){
	return true;
      }
    }
    for (Noeud::iterator it = descendant.begin() ; it != descendant.end(); ++it){  
      if(it.presentfils(N)){
	return return true;
      }
    }
  }
  return false;
}

bool Noeud::supprimeAttribut(string &att){
   for (Noeud::iterator it = listeAttributs.begin() ; it != listeAtrributs.end(); ++it){
     if(*it == att){
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
  if(descendant != null){
    for (Noeud::iterator it = descendant.begin() ; it != descendant.end(); ++it){
      it.affiche(&os);
    }
  }
  return os;
}

  /* Méthode de calcul */

int Noueud::nbAttribut() const{
  if(listeAttribut == null){
    return 0;
  }
  return listeAttribut.size();
}

int Noeud::nbFils() const{
  if(descendant == null){
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
  list textfils();
  for (Noeud::iterator it = descendant.begin() ; it != descendant.end(); ++it){
    if(typeid(it) == typeid(NoeudText)){
      textfils.push_back(&it);
    }
  }
  return textfils;
}

  /* Surcharge d'opérateur */

bool Noeud::operator==(const Noeud &N) const{
  if(nom == N.nom && indentation == N.indentation && pere == N.pere && lignedeb == N.lignedeb && 
     lignefin == N.lignefin && facteurdeb == N.facteurdeb && facteurfin == N.facteurfin){
    if(descendant.size() == N.descendant.size()){
      Noeud::iterator itN = N.descendant.begin();
      for (Noeud::iterator it = descendant.begin() ; it != descendant.end(); ++it){
	if(it == itN){
	  ++itN;
	}
	else return false;
      }
    }
    if(listeAttributs.size() == N.listeAttributs.size()){
      itN = N.listeAttributs.begin();
      for (it = listeAttributs.begin() ; it != listeAttributs.end(); ++it){
	if(it == itN){
	  ++itN;
	}
	else return false;
      }
    }
    return true;
  }
  return false;
}
  
};

/* Surcharge de Flots */
ostream& operator<< (ostream &os, const Noeud &node){
  node.affiche(os);
  return os;
}

//istream& operator>> (istream&, Noeud&);
