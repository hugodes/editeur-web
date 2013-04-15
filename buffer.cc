/**
 * @file buffer.cc
 * @author Hugo des Longchamps
 * @class Buffer
 * @details Surcharge des operateurs << & >>
 */
#include "buffer.h"

/**
 * @brief Constructeur par défaut
 */
Buffer::Buffer(){
    lignes = list<Ligne>();
    strcpy(chemFichTemp, ".nouveau_fichier.tmp");
}

/**
 * @brief Constructeur paramétré
 * @param chemFichier: Le chemin de fichier que l'on souhaite éditer
 */
Buffer::Buffer(char cheminFichier[]){
    lignes = list<Ligne>();
    dom = Dom(lignes);
    setLignes(cheminFichier);
    char *s;
    strcpy(s, ".");
    chemFichTemp = strcat(s, cheminFichier);
    chemFichTemp = strcat(cheminFichier, ".tmp");
}

/**
 * @brief Destructeur
 */
Buffer::~Buffer(){
}

/**
 * @brief Ajouter une ligne
 * @param Ligne: Ligne a ajouter
 * @param int: position de l'ajout
 * */
void Buffer::ajouterLigne(Ligne l, int position){
    list<Ligne>::iterator il = lignes.begin();
    advance(il,position-1);
    lignes.insert(il, l);
    sauvTemp();
    majDom();
}

/**
 * @brief Getter sur Dom
 * @return Dom: le DOM du fichier
 */
Dom Buffer::getDom()const{
    return dom;
}

/**
 * @brief Setter sur Dom
 * @param Dom: remplacer le Dom
 */
void Buffer::setDom(const Dom &d){
    dom = d;
}

/**
 * @brief Getter de lignes
 * @return list<Ligne>: liste des lignes du buffer
 */
list<Ligne> Buffer::getLignes()const{
    return lignes;
}

/**
 * @brief Setter sur lignes
 * @param list<Ligne>: remplacer les lignes
 */
void Buffer::setLignes(const list<Ligne> &l){
    lignes = l;
    sauvTemp();
    majDom();
}

/**
 * @brief Setter sur lignes
 * @param char[]: chemin du fichier pour mettre a jour les lignes
*/
void Buffer::setLignes(char cheminFichier[]){
    FILE * pFichier;
    char buffer[1024];

    pFichier =  fopen(cheminFichier, "r");
    while (!feof(pFichier)){
        if (fgets(buffer, 1024, pFichier)==NULL){
            break;
        }
        Ligne nouvLigne = Ligne(buffer);
        lignes.push_back(nouvLigne);
    }
    fclose(pFichier);
    sauvTemp();
    majDom();
}

/**
 * @brief Affiche
 * @param ostream: flux de sortie
 */
void Buffer::affiche(ostream & os)const{
    //list<Ligne>::iterator il;
    //for (il=lignes.begin(); il!=lignes.end(); il++){
    //    os<<*il;
    //}
}

/**
 * @brief Saisie
 * @param istream: flux d'entrée
 */
void Buffer::saisie(istream &is){
    char buffer[1024];
    cout<<"Entrer un ligne qui serra ajoutée au buffer:\n";
    is.getline(buffer, 1024);
    sauvTemp();
    majDom();
}

/**
 * @brief Sauvegarde dans le fichier temporaire
 */
void Buffer::sauvTemp(){
    FILE * pFichier;
    pFichier = fopen(chemFichTemp, "w");
    list<Ligne>::iterator il;
    for (il=lignes.begin(); il!=lignes.end(); il++){
        fputs((*il).toString(), pFichier);
    }
    fclose(pFichier);
}

/**
 * @brief Mise à jour du Dom
 */
void Buffer::majDom(){
    dom = Dom(lignes);
}

/**
 * @brief Surcharge de l'opérateur de sortie
 * @param ostream: flux de sortie
 * @param Buffer: un Buffer
 * @return ostream: flux de sortie
 */
ostream& operator<<(ostream &os, const Buffer &b){
    b.affiche(os);
    return os;
}

/**
 * @brief Surcharge de l'operateur d'entrée
 * @param istream: flux d'entrée
 * @param Buffer: un Buffer
 * @return istream: flux d'entrée
 */
istream& operator>>(istream &is, Buffer &b){
    b.saisie(is);
    return is;
}




