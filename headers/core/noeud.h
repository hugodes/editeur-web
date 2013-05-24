#ifndef NOEUD_H
#define NOEUD_H

#include <string>
#include <list>
#include <vector>

#include "facteur.h"

using namespace std;
typedef vector<Facteur*> Ligne;


class Noeud{

 private : 
  string nom;
  int indentation;
  list<string> listeAttributs;
  Noeud* pere;
  list<Noeud> descendant;
  Facteur* facteurDeb;
  Facteur* facteurFin;
  int Numligne;
  

 public :

  
  /* Constructeurs */ 
  Noeud();
  Noeud(string&, int, Facteur&, Facteur&);
  Noeud(string&, int, Noeud&, Facteur&, Facteur&);
  Noeud(const Noeud&);
  
  /* Destructeur */
  virtual ~Noeud();

  /* Accesseurs */
  virtual string getNom() const;
  virtual void setNom(string);
  virtual int getIndent() const;
  virtual void setIndent(int);
  virtual Noeud getPere() const;
  virtual void setPere(Noeud*);
  virtual Facteur* getFacteurDeb() const;
  virtual void setFacteurDeb(Facteur);
  virtual Facteur* getFacteurFin() const;
  virtual void setFacteurFin(Facteur);

  /* Méthodes pour modifier le noeud */
  virtual void ajoutAttribut(string);
  virtual void ajoutfils(Noeud);
  virtual void ajoutFils(vector< Noeud >&);
  virtual bool presentfils(const Noeud&) const;    // vérifie si un noeud est présent dans la liste des fils du noeud courant
  virtual bool supprimeAttribut(string&);

  /* Méthode d'affichage */
 
  virtual ostream& affiche(ostream&) const;

  /* Méthode de calcul */
  virtual int nbAttribut() const;
  virtual int nbFils() const;
  virtual int indent() const;

  /* Méthode d'accès au fils */
  virtual list<Noeud> retournerNodesFils();
  virtual list<Noeud> retournerTextFils();

  /* Surcharge d'opérateur */
  virtual bool operator==(const Noeud&) const; 
  
};

/* Surcharge de Flots */
ostream& operator<< (ostream&, const Noeud&);


#endif
