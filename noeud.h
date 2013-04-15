#ifndef NOEUD_H
#define NOEUD_H

#include <string>
#include <list>
#include "ligne.h"
//#include "noeudtexte.h"

using namespace std;

//typedef std::list<Objet> Obj_list;
/*class Noeud;
class DOMText : public Noeud{

private :
    string text;

public :
	DOMText ();
	~DOMText();
	DOMText(string);
};
*/



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
  Noeud(string, int, Noeud&, Ligne&, Ligne&, Facteur&, Facteur&);
  Noeud(const Noeud&);
  
  /* Destructeur */
  virtual ~Noeud();

  /* Accesseurs */
  virtual string getNom() const;
  virtual void setNom(string);
  virtual int getIndent() const;
  virtual void setIndent(int);
  virtual Noeud getPere() const;
  virtual void setPere(Noeud);
  virtual Ligne* getLigneDeb() const;
  virtual void setLigneDeb(Ligne);
  virtual Ligne* getLigneFin() const;
  virtual void setLigneFin(Ligne);
  virtual Facteur* getFacteurDeb() const;
  virtual void setFacteurDeb(Facteur);
  virtual Facteur* getFacteurFin() const;
  virtual void setFacteurFin(Facteur);

  /* Méthodes pour modifier le noeud */
  virtual void ajoutAttribut(string);
  virtual void ajoutfils(Noeud);
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
  //  virtual Noeud& operator=(const Noeud&);
  
};

/* Surcharge de Flots */
ostream& operator<< (ostream&, const Noeud&);
//istream& operator>> (istream&, Noeud&);

#endif
