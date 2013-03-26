//Créateur: Nicolas Emeri
//Modifications: Nicolas Emeri & Bryan Libourel

#include "facteur.h"
#include <iostream>
#include <string.h>

using namespace std;

/* Constructeur de facteur */
/*		text : texte du facteur */
facteur::facteur(char* text) {
	strcpy(this->texte,text);
	strcpy(this->couleur,"black");
	this->formate();
}

/* Destructeur de facteur */
facteur::~facteur() {
    delete this->texte ;
    delete this->couleur ;
    delete this->texteFormate ;
}

/* Definir le texte */
/*		text : texte du facteur */
void facteur::setTexte(char* text) {
    strcpy(this->texte, text);
    this->formate();
}

/* Definir la couleur */
/*		color : couleur du facteur */
void facteur::setCouleur(char* color) {
    strcpy(this->couleur, color);
    this->formate();
}

/* Retourne le texte du facteur */
char* facteur::getTexte() {
    return(this->texte);
}

/* Retourne le texte du facteur formaté avec la couleur */
char* facteur::getTexteFormate() {
	return(this->texteFormate) ;
}

/* Formate puis stock le texte */
void facteur::formate() {
    this->texteFormate = new char [strlen(this->couleur)+strlen(this->texte)+27];
    strcpy(this->texteFormate, "<div style='color:");
	strcat(this->texteFormate, this->couleur);
	strcat(this->texteFormate, ";'>");
	strcat(this->texteFormate, this->texte);
	strcat(this->texteFormate, "</div>");
}
