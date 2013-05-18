
/**
 *  @author SAKINE HAMID
 *  @file facteur.h 
 */
#ifndef noeudtexte_h
#define noeudtexte_h

#include <iostream>
#include <string>
using namespace std;
#include "noeud.h"

/*
*@class NoeudTexte
*/
class NoeudTexte {

private :
    string text;

public :
	NoeudTexte();/** @fn Constructeur noeudtexte */
	NoeudTexte(string);
	~NoeudTexte();/** @fn Destructeur noeudtexte */
	void setText(string);/** @fn Definir le texte */
};



#endif
