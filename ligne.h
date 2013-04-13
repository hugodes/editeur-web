/**
*@author Amazigh Haddadou 
*/
#ifndef DEF_LIGNE
#define DEF_LIGNE

#include <vector>
#include"facteur.h"
#include<string>
#include<cstring>
using namespace std;
#include<iostream>
#include <iterator>
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
		Ligne(const char*); /** @fn Constructeur de ligne */
		char* toString(); /** @fn Retourne une ligne */
		void affiche(ostream &)const; /** @fn Retourne le text d'une ligne */
};

ostream& operator<<(ostream &, const Ligne &); /** Surcharge de l'operateur << */

#endif
