//Créateur: Hugo des Longchamps
//Modificatins: Hugo des Longchamps
#ifndef buffer_h
#define buffer_h

#include <iostream>
#include <list>
#include <iterator>
using namespace std;
#include "dom.h"
#include "Ligne.h"

class Buffer{
    private:
        Dom dom;
        list<Ligne> lignes;
        //chemin vers le fichier de sauvegarde temp.
        char *chemFichTemp;
    public:
        Buffer();
        Buffer(char cheminFichier[]);
        ~Buffer();
        void ajouterLigne(Ligne l, int position);
        Dom getDom()const;
        void setDom(const Dom &);
        list<Ligne> getLignes()const;
        void setLignes(const list<Ligne> &);
        void setLignes(char cheminFichier[]);
        void affiche(ostream &)const;
        void saisie(istream &);
        //sauvegarde le buffer dans un fichier temporaire
        void sauvTemp();
        //met a jours le dom à partir du fichier temporaire
        void majDom();
};

ostream& operator<<(ostream &, const Buffer &);
istream& operator>>(istream &, Buffer &);

#endif
