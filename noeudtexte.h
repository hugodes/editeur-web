
/**
 *  @author SAKINE HAMID
 *  @file facteur.h 
 */
#ifndef DOMText_h
#define DOMText_h

#include <iostream>
#include <string>
#include "noeud.h"

using namespace std;



/*

*@class <nom> [noeudtexte.h] [./noeudtexte.h]  

*/

class DOMText {

private :
    string text;

public :
	DOMText ();/** @fn Constructeur noeudtexte */
	~DOMText() {};/** @fn Destructeur noeudtexte */
	void setText(string);/** @fn Definir le texte */
};



#endif
