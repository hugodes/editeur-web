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
        //chemin vers le fichier de sauvegarde temp.
        char chemFichTemp[1024]
    public:
        Buffer();
        Buffer(char cheminFichier[]);
        ~Buffer();
        void ajouterLigne(Ligne l, int position);
        DOM getDom()const;
        void setDom(const DOM &);
        list<Ligne> getLignes()const;
        void setLignes(const list<Ligne> &);
        void setLignes(char cheminFichier[]);
        void affiche(ostream &)const;
        void saisie(istream &);
        //sauvegarde le buffer dans un fichier temporaire
        void sauvTemp();
        //met a jours le dom à partir du fichier temporaire
        void majDOM();
};

ostream& operator<<(ostream &, const Buffer &);
istream& operator>>(istream &, Buffer &);

#endif
