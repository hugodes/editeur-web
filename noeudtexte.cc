/**
 *  @author SAKINE HAMID
 *   @file noeudtexte.h 
 */

#include <string>
using namespace std;
#include "noeud.h"
#include "noeudtexte.h"

/** @fn Constructeur de facteur  */
NoeudTexte::NoeudTexte() {

}
/** @fn Constructeur de facteur  */
NoeudTexte::NoeudTexte(string s) {
    text=s;
}
/** @fn Destructeur de facteur  */
NoeudTexte::~NoeudTexte() {

}
/** @fn Definir le texte  */
void NoeudTexte::setText(string S){
	text=S;
}
