/*
 * @file dom.h
 * @author Hugo des Longchamps & Ahmed Rafik 
 * @details surcharge des operateurs <<
 */

#ifndef DOM_H
#define DOM_H

#include <iostream>
#include <map>
#include "facteur.h"
#include "noeud.h"

using namespace std;

/** @class Dom
 *  Cette Classe représente l'arbre DOM d'un site internet
 */

class Dom{

 private : 
  Noeud racine;

 public :

  
  /* Constructeurs */ 

  /**
  * @brief Constructeur par défaut
  */
  Dom();
  /**
   * @brief Constructeur à partir d'un Noeud
   */
  Dom(Noeud&);
  /**
   * @brief Constructeur à partir d'une liste de Ligne
   */
  Dom(list<Ligne>);
  
  /* Destructeur */

 /**
  * @brief Destructeur 
  */
  virtual ~Dom();

  /* Accesseurs racine */
 /**
  * @brief Accesseur de lecture de la racine du DOM
  * @return Noeud : le Noeud racine du DOM
  */

  Noeud getRacine()const;

  /* Méthodes pour modifier le DOM */
   /**
    * @brief Ajouter un Noeud
    * @param Noeud Pere : Noeud présent dans le DOM auquel on ajoute un fils
    * @param Noeud Fils : Noeud que l'on ajoute au DOM en tant que fils de "Pere"
    * @return Bool : True si l'ajout s'est bien passé 
    * */
  // virtual bool ajoutNoeud(Noeud Pere, Noeud Fils);

   /**
    * @brief Vérifie la présence d'un noeud dans le DOM
    * @param Noeud : Noeud qui va être rechercher dans le DOM
    * @return bool : True si le noeud fait partie du DOM
    * */

  virtual bool noeudPresent(const Noeud);

  /* Méthode d'affichage */
   /**
    * @brief Affichage du DOM
    * @param ostream : Flot de sortie qui va recevoir l'affichage du DOM
    * @return ostream : Flot de sortie qui va nous permettre d'afficher le DOM
    * */

  virtual ostream& affiche(ostream&) const;

  /* Méthode de calcul */
   /**
    * @brief Calcul du nombre de Noeud du DOM
    * @return int : Le nombre de noeud dans le DOM
    * */

  //virtual int nbNoeud() const;

  /* méthode d'information graphique */
   /**
    * @brief Recherche de l'indentation d'un noeud du DOM
    * @param Noeud : Le noeud dont on veut connaitre l'indentation
    * @return int : L'indentation du noeud passé en paramètre
    * */

  virtual int retournerTabLigne(Noeud);
  
};

/* Surcharge de Flots */
   /**
    * @brief Surcharge de l'opérateur d'affichage <<
    * @param ostream& : flot de sortie sur lequel est affiché le DOM
    * @param Dom&: Arbre Dom que l'on veut afficher
    * @return ostream& : flot contenant l'affichage du DOM qui va être envoyer sur la sortie standard
    * */

ostream& operator<< (ostream&, const Dom&);

#endif
