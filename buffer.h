/*
 * @file buffer.h
 * @author Hugo des Longchamps
 * @details surcharge des operateurs << & >>
 */
#ifndef buffer_h
#define buffer_h

#include <iostream>
#include <cstdio>
#include <list>
#include <iterator>
using namespace std;
#include "dom.h"
#include "ligne.h"

/** @class Buffer
 *  Cette Classe représente le contenu visible dans l'éditeur
 */
class Buffer{
    private:
        Dom dom;
        list<Ligne> lignes;
        char *chemFichTemp;

    public:

        Buffer();/** @fn Constructeur par défaut */
        Buffer(char cheminFichier[]);/** @fn Constructeur paramétré*/
        ~Buffer();/** @fn Destructeur */
        void ajouterLigne(Ligne l, int position);/** @fn Ajouter une ligne */
        Dom getDom()const;/** @fn Getter du Dom */
        void setDom(const Dom &);/** @fn Setter du Dom */
        list<Ligne> getLignes()const;/** @fn Getter des lignes */
        void setLignes(const list<Ligne> &);/** @fn Setter des lignes */
        void setLignes(char cheminFichier[]);/** @fn Setter des lignes */
        void affiche(ostream &)const;/** @fn Affichage */
        void saisie(istream &);/** @fn Saisie */
        void sauvTemp();/** @fn Sauvegarde dans le fichier temporaire*/
        void majDom();/** @fn Mise a jour du Dom */
};

ostream& operator<<(ostream &, const Buffer &);/** @fn Surcharge de l'operateur d'entrée */
istream& operator>>(istream &, Buffer &);/** @fn Surcharge de l'operateur de sortie*/

#endif
