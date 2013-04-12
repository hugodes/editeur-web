#ifndef NOEUD_H
#define NOEUD_H

#include <string>
#include <list>
#include "ligne.h"
#include "facteur.h"

using namespace std;

//typedef std::list<Objet> Obj_list;

class Noeud{

 private : 
  string nom;
  int indentation;
  list<string> listeAttributs;
  Noeud* pere;
  list<Noeud> descendant;
  Ligne* lignedeb;
  Ligne* lignefin;
  Facteur* facteurDeb;
  Facteur* facteurFin;
  

 public :

  
  /* Constructeurs */ 
  Noeud();
  Noeud(string, int, Noeud*, Ligne*, Ligne*, Facteur*, Facteur*);
  Noeud(const Noeud&);
  
  /* Destructeur */
  virtual ~Noeud();

  /* Accesseurs */
  virtual string getNom() const;
  virtual void setNom(string);
  virtual Noeud getPere() const;
  virtual void setPere(Noeud&);
  virtual int getLigneDeb() const;
  virtual void setLigneDeb(Ligne&);
  virtual int getLigneFin() const;
  virtual void setLigneFin(Ligne&);
  virtual int getFacteurDeb() const;
  virtual void setFacteurDeb(Facteur&);
  virtual int getFacteurFin() const;
  virtual void setFacteurFin(Facteur&);

  /* Méthodes pour modifier le noeud */
  virtual void ajoutAttribut(string);
  virtual void ajoutfils(const Noeud&);
  virtual bool presentfils(const Noeud&) const;    // vérifie si un noeud est présent dans la liste des fils du noeud courant
  virtual bool supprimeAttribut(string&);

  /* Méthode d'affichage */
  // virtual istream& saisie(istream&);
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
//istream& operator>> (istream&, Noeud&);

#endif
