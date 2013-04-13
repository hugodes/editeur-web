/**
* @file facteur.h
* @author Nicolas EMERI & Bryan LIBOUREL
* @details surcharge de l'operateur <<
*/

#ifndef DEF_FACTEUR
#define DEF_FACTEUR

#include <iostream>
#include <string.h>

using namespace std;

/**
* @class facteur facteur.h
*/
class Facteur {

	private:
		char* texte;
		char* couleur;
		char* texteFormate;

	public:
	    Facteur(); /** @fn Constructeur par defaut */
		Facteur(char* text); /** @fn Constructeur de facteur */
		~Facteur(); /** @fn Destructeur de facteur */
		void setTexte(char* text); /** @fn Definir le texte  */
		char* getTexte(); /** @fn Retourne le texte du facteur */
		char* getTexteFormate(); /** @fn Retourne le texte du facteur formaté avec la couleur */
		void setCouleur (char* color); /** @fn Definir la couleur */
		void formate(); /** @fn Formate puis stock le texte */
};

ostream& operator<<(ostream & flux, const Facteur &f); /** @fn Surcharge l'operateur << */

#endif
