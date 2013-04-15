
/**
 *  @author SAKINE HAMID
 *  @file facteur.h 
 */
#ifndef domtext_h
#define domtext_h

#include <iostream>
#include <string>
<<<<<<< HEAD
#include "noeud.h"
=======
>>>>>>> af78fbff3525a8bf91a61e640662993f049af00e
using namespace std;

#include "noeud.h"


<<<<<<< HEAD

=======
/*

*@class <nom> [noeudtexte.h] [./noeudtexte.h]  

*/
>>>>>>> af78fbff3525a8bf91a61e640662993f049af00e
class DOMText : public Noeud{

private :
    string text;

public :
	noeudtexte ();/** @fn Constructeur noeudtexte */
	~noeudtexte();/** @fn Destructeur noeudtexte */
	void setText(string);/** @fn Definir le texte */
};



#endif
