/**
* @file facteur.h
* @author Nicolas EMERI & Bryan LIBOUREL
* @details surcharge de l'operateur <<
*/

#ifndef facteur_h
#define facteur_h

#include <iostream>
#include <string.h>

using namespace std;

/**
* @class Facteur
*/
class Facteur {

	private:
		char* texte;
		char* couleur;
		char* texteFormate;

	public:
	    Facteur(); /** @fn Constructeur par defaut */
		Facteur(char* text); /** @fn Constructeur de facteur */
		Facteur(const Facteur&); /** @fn Constructeur par copie */
		~Facteur(); /** @fn Destructeur de facteur */
		void setTexte(char* text); /** @fn Definir le texte  */
		char* getTexte()const; /** @fn Retourne le texte du facteur */
		char* getTexteFormate(); /** @fn Retourne le texte du facteur formaté avec la couleur */
		void setCouleur (char* color); /** @fn Definir la couleur */
		void formate(); /** @fn Formate puis stock le texte */
		int taille()const; /** @fn Renvoi la taille de texte */
};

ostream& operator<<(ostream & flux, const Facteur &f); /** @fn Surcharge l'operateur << */

#endif
