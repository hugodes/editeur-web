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
#include <vector>
using namespace std;
#include "facteur.h"
#include "dom.h"

/** @class Buffer
 *  Cette Classe représente le contenu visible dans l'éditeur
 */
typedef vector<Facteur> Ligne;
class Buffer{
    private:
        Dom dom;
        list<Ligne> lignes;
        char *chemFichTemp;

    public:

        /**
         * @brief Constructeur par défaut
         */
        Buffer();
        /**
         * @brief Constructeur paramétré
         * @param chemFichier: Le chemin de fichier que l'on souhaite éditer
         */
        Buffer(char cheminFichier[]);
        /**
         * @brief Destructeur
         */
        ~Buffer();
        /**
         * @brief Ajouter une ligne
         * @param Ligne: Ligne a ajouter
         * @param int: position de l'ajout
         * */
        void ajouterLigne(Ligne l, int position);
        /**
         * @brief Getter sur Dom
         * @return Dom: le DOM du fichier
         */
        Dom getDom()const;
        /**
         * @brief Setter sur Dom
         * @param Dom: remplacer le Dom
         */
        void setDom(const Dom &);
        /**
         * @brief Getter de lignes
         * @return list<Ligne>: liste des lignes du buffer
         */
        list<Ligne> getLignes()const;
        /**
         * @brief Setter sur lignes
         * @param list<Ligne>: remplacer les lignes
         */
        void setLignes(const list<Ligne> &);
        /**
        * @brief Setter sur lignes
        * @param char[]: chemin du fichier pour mettre a jour les lignes
        */
        void setLignes(char cheminFichier[]);
        /**
         * @brief Affiche
         * @param ostream: flux de sortie
         */
        void affiche(ostream &)const;
        /**
         * @brief Saisie
         * @param istream: flux d'entrée
         */
        void saisie(istream &);
        /**
         * @brief Sauvegarde dans le fichier temporaire
         */
        void sauvTemp();
        /**
         * @brief Mise à jour du Dom
         */
        void majDom();
};

/**
 * @brief Surcharge de l'opérateur de sortie
 * @param ostream: flux de sortie
 * @param Buffer: un Buffer
 * @return ostream: flux de sortie
 */
ostream& operator<<(ostream &, const Buffer &);
/**
 * @brief Surcharge de l'operateur d'entrée
 * @param istream: flux d'entrée
 * @param Buffer: un Buffer
 * @return istream: flux d'entrée
 */
istream& operator>>(istream &, Buffer &);

#endif
