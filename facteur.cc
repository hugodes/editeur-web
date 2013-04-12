/**
* @file facteur.cc
* @author Nicolas EMERI & Bryan LIBOUREL
* @class Facteur facteur.h "./facteur.h"
* @details surcharge de l'operateur <<
*/

#include "facteur.h"
#include <iostream>
#include <string.h>

using namespace std;

/**
* @brief Constructeur de facteur 
* @param text texte du facteur
*/
Facteur::Facteur(char* text) {
	strcpy(this->texte,text);
	strcpy(this->couleur,"black");
	this->formate();
}

/**
* @brief Destructeur de facteur
*/
Facteur::~Facteur() {
    delete this->texte ;
    delete this->couleur ;
    delete this->texteFormate ;
}

/**
* @brief Definir le texte 
* @param text texte du facteur
*/
void Facteur::setTexte(char* text) {
    strcpy(this->texte, text);
    this->formate();
}

/**  
* @brief Definir la couleur
* @param color couleur du facteur 
*/
void Facteur::setCouleur(char* color) {
    strcpy(this->couleur, color);
    this->formate();
}

/**
* @brief Retourne le texte du facteur 
* @return retourne le texte du facteur
*/
char* Facteur::getTexte() {
    return(this->texte);
}

/**
* @brief Retourne le texte du facteur formaté avec la couleur 
* @return retourne le texte du facteur formate
*/
char* Facteur::getTexteFormate() {
	return(this->texteFormate) ;
}

/**
* @brief Formate puis stock le texte 
*/
void Facteur::formate() {
    this->texteFormate = new char [strlen(this->couleur)+strlen(this->texte)+27];
    strcpy(this->texteFormate, "<div style='color:");
	strcat(this->texteFormate, this->couleur);
	strcat(this->texteFormate, ";'>");
	strcat(this->texteFormate, this->texte);
	strcat(this->texteFormate, "</div>");
}

/**
* @brief Surcharge l'operateur << 
* @return le flux de sortie ostream
*/
ostream& operator<<(ostream &flux, const Facteur &f){
    flux << f.getTexteFormate();
    return flux;
}
