/**
*@author Amazigh Haddadou 
*/
#ifndef DEF_LIGNE
#define DEF_LIGNE

#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <iostream>
using namespace std;
#include "facteur.h"
/**
* @classe Facteur facteur.h
*/
class Ligne
{

	private:
		int indentUtil;
		vector<Facteur> ligne;

	public:
		Ligne();/** @fn Constructeur par defaut de ligne */
		~Ligne(); /** @fn Destructeur de ligne */
		Ligne(vector<Facteur>); /** @fn Constructeur de ligne */
		Ligne(char*); /** @fn Constructeur de ligne */
		char* toCString(); /** @fn Retourne une ligne */
		string toString(); /** @fn Retourne une ligne */
		void affiche(ostream &); /** @fn Retourne le text d'une ligne */
};

ostream& operator<<(ostream &,Ligne &); /** Surcharge de l'operateur << */

#endif
