
/**
 *  @author SAKINE HAMID
 *  @file facteur.h 
 */
#ifndef domtext_h
#define domtext_h
/*

*@class <nom> [noeudtexte.h] [./noeudtexte.h]  

*/
using namespace std;
#include "noeud.h"
#include <string>
#include <iostream>


class noeudtexte{

private :
    string text;

public :
	noeudtexte ();/** @fn Constructeur noeudtexte */
	~noeudtexte();/** @fn Destructeur noeudtexte */
	void setText(string);/** @fn Definir le texte */
};





#endif
