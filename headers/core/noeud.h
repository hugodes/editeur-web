/*
 * @file noeud.h
 * @author Hugo des Longchamps & Ahmed Rafik
 * @details surcharge des operateurs << & ==
 */

#ifndef NOEUD_H
#define NOEUD_H

#include <string>
#include <list>
#include <vector>

#include "facteur.h"

using namespace std;

/** @class Noeud
 *  Cette Classe représente les Noeuds de l'arbre DOM
 */

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

  /**
  * @brief Constructeur par défaut
  */
  Noeud();
  /**
  * @brief Constructeur parametré de noeud orphelin
  */
  Noeud(string&, int, Facteur&, Facteur&);
 /**
  * @brief Constructeur parametré de Noeud avec un père
  */
  Noeud(string&, int, Noeud&, Facteur&, Facteur&);
 /**
  * @brief Constructeur par copie
  */
  Noeud(const Noeud&);
  
  /* Destructeur */
 /**
  * @brief Destructeur
  */
  virtual ~Noeud();

  /* Accesseurs */

  /**
  * @brief Accesseur de lecture sur le nom du Noeud
  * @return string : le nom du Noeud 
  */
  virtual string getNom() const;
  /**
  * @brief Accesseur de saisie du nom
  * @param string : le nom que l'on veut donnée au Noeud
  */ 
 virtual void setNom(string);
 /**
  * @brief Accesseur de lecture sur l'indentation du Noeud
  * @return int : l'indentation du noeud
  */
  virtual int getIndent() const;
  /**
  * @brief Accesseur de saisie de l'indentation du Noeud
  * @param int : L'indentation que l'on veut donnée au Noeud
  */
  virtual void setIndent(int);
  /**
  * @brief Accesseur de lecture sur le Noeud père du Noeud courant
  * @return Noeud : le Noeud Père du Noeud courant
  */
  virtual Noeud getPere() const;
  /**
  * @brief Accesseur de saisie du père du Noeud
  * @param Noeud : Le Noeud que l'on veut assigné en tant que père
  */
  virtual void setPere(Noeud*);
  /**
  * @brief Accesseur de lecture sur le facteur débutant le noeud
  * @return Facteur* : Un pointeur un le premier facteur du noeud
  */
  virtual Facteur* getFacteurDeb() const;
  /**
  * @brief Accesseur de saisie du facteur débutant le noeud
  * @param Facteur : Le facteur que sera le premier facteur du noeud
  */
  virtual void setFacteurDeb(Facteur);
  /**
  * @brief Accesseur de lecture sur le facteur terminant le noeud
  * @return Facteur* : Un pointeur un le dernier facteur du noeud
  */
  virtual Facteur* getFacteurFin() const;
  /**
  * @brief Accesseur de saisie du facteur terminant le noeud
  * @param Facteur : Le facteur que sera le dernier facteur du noeud
  */
  virtual void setFacteurFin(Facteur);

  /* Méthodes pour modifier le noeud */
  /**
   * @brief Ajouter un Attribut
   * @param String : Attribut à ajouter
   * */
  virtual void ajoutAttribut(string);
  /**
   * @brief Ajouter un fils
   * @param Noeud : Noeud à ajouter à la list des fils 
   * */
  virtual void ajoutfils(Noeud*);
  /**
   * @brief Ajouter une descendance
   * @param vector<Noeud&> : Vecteur de noeud contenant la descendance à ajouter
   * */
  //virtual void ajoutfils(vector< Noeud >&);
  /**
    * @brief Recherche d'un éventuel fils
    * @param Noeud& : Noeud que l'on va rechercher parmi les fils
    * @return Bool : True si le Noeud est un fils
    * */
  virtual bool presentfils(const Noeud&) const;    // vérifie si un noeud est présent dans la liste des fils du noeud courant
  /**
    * @brief Enlever un attribut du Noeud
    * @param string& : attribut à retirer
    * @return Bool : True si la supression s'est bien passé 
    * */
  virtual bool supprimeAttribut(string&);

  /* Méthode d'affichage */

  /**
    * @brief Affichage du Noeud
    * @param ostream : Flot de sortie qui va recevoir l'affichage du Noeud
    * @return ostream : Flot de sortie qui va nous permettre d'afficher le Noeud
    * */
  virtual ostream& affiche(ostream&) const;

  /* Méthode de calcul */

  /**
   * @brief Calcul du nombre d'attribut du Noeud
   * @return int : Le nombre d'attribut dans le Noeud
   * */
  virtual int nbAttribut() const;
  /**
   * @brief Calcul du nombre de fils du Noeud 
   * @return int : Le nombre de fils du Noeud 
   * */
  virtual int nbFils() const;
 /**
    * @brief Calcul du nombre de Noeud du DOM
    * @return int : Le nombre de noeud dans le DOM
    * */


  /* Méthode d'accès au fils */
/**
  * @brief Accesseur de lecture sur la list des fils du noeud courant
  * @return list<Noeud> : La list des fils (descendant)
  */
  virtual list<Noeud> retournerNodesFils();
/**
  * @brief Accesseur de lecture sur la list des fils de type NoeudText
  * @return list<Noeud> : Une list issue de descendant, contenant tout les NoeudText 
  */
  virtual list<Noeud> retournerTextFils();

  /* Surcharge d'opérateur */
  /**
   * @brief Surcharge de l'opérateur d'affichage ==
   * @param Noeud& : Noeud que l'on souhaite comparer au noeud courant
   * @return bool : True si le Noeud en paramètre à les même attribut que le Noeud courant
   * */
  virtual bool operator==(const Noeud&) const; 
  
};

/* Surcharge de Flots */
 /**
    * @brief Surcharge de l'opérateur d'affichage <<
    * @param ostream& : flot de sortie sur lequel est affiché le Noeud
    * @param Noeud&: Noeud que l'on veut afficher
    * @return ostream& : flot contenant l'affichage du Noeud qui va être envoyer sur la sortie standard
    * */
ostream& operator<< (ostream&, const Noeud&);


#endif
