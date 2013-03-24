//Créateur: Hugo des Longchamps
//Modificatins: Hugo des Longchamps
#ifndef buffer_h
#define buffer_h

#include <iostream>
using namespace std;
#include "DOM.h"
#include "Ligne.h"

class Buffer{
    private:
        DOM dom;
        list<Ligne> lignes;
    public:
        Buffer();
        Buffer(File *);
        ~Buffer();
        //Nouvelle ligne retourne true si l'ajout c'est bien déroulé
        //retourne fasle sinon.
        bool nouvelleLigne(int indentation, int position);
        DOM getDom()const;
        void setDom(const DOM &)
        list<Ligne> getLignes()const;
        void setLignes(const list<ligne> &);
        void affiche(ostream &)const;
        void saisie(istream &);
};

ostream& operator<<(ostream &, const Buffer &);
istream& operator>>(istream &, Buffer &);

#endif
