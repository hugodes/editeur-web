/**
* @file facteur.cc
* @author Nicolas EMERI & Bryan LIBOUREL
* @class Facteur
* @details surcharge de l'operateur <<
*/

#include "facteur.h"

/**
* @brief Constructeur par défaut
*/
Facteur::Facteur(){
    texte=NULL;
    couleur=NULL;
    texteFormate=NULL;
}

/**
* @brief Constructeur de facteur 
* @param text texte du facteur
*/
Facteur::Facteur(char* text) {
	texte = new char[sizeof(text)];
	strcpy(this->texte,text);
	couleur = new char[256];
	strcpy(this->couleur,"black");
	this->formate();
}

/**
 * @brief Constructeur par copie de Facteur
 * @param Facteur: un objet Facteur
 */
Facteur::Facteur(const Facteur& f){
    this->texte=new char[sizeof(f.texte)];
    strcpy(this->texte, f.texte);
    this->couleur=new char[sizeof(f.couleur)];
    strcpy(this->couleur, f.couleur);
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
char* Facteur::getTexte()const {
    //char *texte_renvoi = new char[sizeof(texte)];
    //return(texte_renvoi);
    return(this->texte) ;
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
    this->texteFormate = new char [strlen(this->couleur)+strlen(this->texte)+64];
    strcpy(this->texteFormate, "<span style='color:");
	strcat(this->texteFormate, this->couleur);
	strcat(this->texteFormate, ";'>");
	strcat(this->texteFormate, this->texte);
	strcat(this->texteFormate, "</span>");
}

/**
* @brief Methode taille()
* @return la taille de texte
* retourne -1 si texte n'est pas initialisé
*/
int Facteur::taille()const{
    if(texte==NULL){
        return -1;
    }
    int taille=0;
    int i=0;
    while(texte[i]!='\0'){
        taille++;
        i++;
    }
    return taille;
}

Facteur& Facteur::operator=(const Facteur& f){
    if (texte){
        delete texte;
    }
    texte=new char[sizeof(f.texte)];
    copieChar(texte, f.texte);

    if(couleur){
        delete couleur;
    }
    couleur=new char[sizeof(f.couleur)];
    copieChar(couleur, f.couleur);

    if (texteFormate){
        delete texteFormate;
    }
    couleur=new char[sizeof(f.texteFormate)];
    copieChar(texteFormate, f.texteFormate);
}


/**
* @brief Surcharge l'operateur << 
* @return le flux de sortie ostream
*/
ostream& operator<<(ostream &flux, const Facteur &f){
    //sur cette methode, f est const, il faut donc en faire une copie
    cout<<"J'en suis ici"<<endl;
    Facteur copie_facteur(f);
    string t(copie_facteur.getTexteFormate());
    flux << t;
    return flux;
}
void copieChar(char* c1, const char* c2){
    int taille=sizeof(c2);
    for (int i=0; i<taille; i++){
        c1[i]=c2[i];
    }
}
