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
		int jeton;

	public:
	    Facteur(); /** @fn Constructeur par defaut */
        Facteur(char*& text, int &flag); /** @fn Constructeur de facteur */
		Facteur(const Facteur&); /** @fn Constructeur par copie */
		~Facteur(); /** @fn Destructeur de facteur */
		void setTexte(char* text); /** @fn Definir le texte  */
		char* getTexte()const; /** @fn Retourne le texte du facteur */
		char* getTexteFormate()const; /** @fn Retourne le texte du facteur formaté avec la couleur */
		void setCouleur (char* color); /** @fn Definir la couleur */
		void formate(); /** @fn Formate puis stock le texte */
		int taille()const; /** @fn Renvoi la taille de texte */
        const char* chercherConfCouleur(int flag); /** @fn Renvoi la couleur en fonction d'un jeton */
        Facteur& operator=(const Facteur&); /** @fn Surcharge l'operateur = Renvoi la copie */
		int getJeton(); /** @fn Retourne le jeton du facteur */
};

ostream& operator<<(ostream & flux, const Facteur &f); /** @fn Surcharge l'operateur << */
void copieChar(char*, const char*);/** @fn copie le contenu du deuxième char* dans le premier */

#endif
