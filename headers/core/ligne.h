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
* @classe Ligne Ligne.h
*/
class Ligne
{

private:
int indentUtil;
vector<Facteur> ligne;

public:
Ligne();/** @fn Constructeur par defaut de ligne */
Ligne(vector<Facteur>); /** @fn Constructeur de ligne */
Ligne(char*&); /** @fn Constructeur de ligne */
Ligne(const Ligne&);/** @fn Constructeur par copie */
~Ligne(); /** @fn Destructeur de ligne */
char* toCString(); /** @fn Retourne une ligne */
string toString(); /** @fn Retourne une ligne */
void affiche(ostream &)const; /** @fn Retourne le text d'une ligne */
//Ligne& operator=(const Ligne&);/** @fn surcharge de l'opérateur = */
};

ostream& operator<<(ostream &,const Ligne &); /** Surcharge de l'operateur << */

#endif
