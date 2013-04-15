
/**
 *  @author SAKINE HAMID
 *  @file facteur.h 
 */
#ifndef domtext_h
#define domtext_h

#include <iostream>
#include <string>
using namespace std;

#include "noeud.h"


/*

*@class <nom> [noeudtexte.h] [./noeudtexte.h]  

*/
class DOMText : public Noeud{

private :
    string text;

public :
	noeudtexte ();/** @fn Constructeur noeudtexte */
	~noeudtexte();/** @fn Destructeur noeudtexte */
	void setText(string);/** @fn Definir le texte */
};



#endif
