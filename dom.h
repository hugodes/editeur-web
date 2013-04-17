#ifndef DOM_H
#define DOM_H

#include <string>
#include <list>
#include "ligne.h"
#include "facteur.h"
#include "noeud.h"

using namespace std;

class Dom{

 private : 
  Noeud racine;

 public :

  
  /* Constructeurs */ 
  Dom();
  Dom(Noeud&);
  Dom(list<Ligne>);
  
  /* Destructeur */
  virtual ~Dom();

  /* Méthodes pour modifier le DOM */
  virtual bool ajoutNoeud(Noeud, Noeud);
  // virtual bool supprimeNoeud(Noeud&);
  virtual bool noeudPresent(const Noeud);

  /* Méthode d'affichage */
  //virtual istream& saisie(istream&);
  virtual ostream& affiche(ostream&) const;

  /* Méthode de calcul */
  //virtual int nbNoeud() const;

  /* méthode d'information graphique */
  virtual int retournerTabLigne(Noeud);
  //virtual Noeud retournerPtrNode(Ligne);
  //  virtual int indentFormelle(Ligne);
  
};

/* Surcharge de Flots */
ostream& operator<< (ostream&, const Dom&);
//istream& operator>> (istream&, Noeud&);

#endif
