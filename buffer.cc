//Créateur: Hugo des Longchamps
////Modifications: Hugo des Longchamps
#include "buffer.h"

Buffer::Buffer(){
    dom = NULL;
    lignes = NULL;
    strcpy(chemFichTemp, ".nouveau_fichier.tmp");
}

Buffer::Buffer(char cheminFichier[]){
    //dom = DOM(cheminFichier);
    setLignes(cheminFichier);
    char *s;
    strcpy(s, ".");
    chemFichTemp = strcat(s, cheminFichier);
    chemFichTemp = strcat(cheminFichier, ".tmp");
}

Buffer::~Buffer(){
}

void Buffer::ajouterLigne(Ligne l, int position){
    list<Ligne>::iterator il;
    il+=(position-1);
    lignes.insert(il, l);
    sauvTemp();
    majDom();
}

Dom Buffer::getDom()const{
    return dom;
}

void Buffer::setDom(const Dom &d){
    dom = d;
}

list<Ligne> Buffer::getLignes()const{
    return lignes;
}

void Buffer::setLignes(const list<Ligne> &l){
    lignes = l;
    sauvTemp();
    majDom();
}

void Buffer::setLignes(char cheminFichier[]){
    FILE * pFichier;
    char buffer[1024];

    if (lignes == NULL){
        lignes = list<Ligne>();
    }

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

void Buffer::affiche(ostream & os)const{
    list<Ligne>::iterator il;
    for (il=lignes.begin(); il!=lignes.end(); il++){
        os<<*il;
    }
}

void Buffer::saisie(istream &is){
    char buffer[1024];
    cout<<"Entrer un ligne qui serra ajoutée au buffer:\n";
    is.getline(buffer, 1024);
    sauvTemp();
    majDom();
}

void Buffer::sauvTemp(){
    FILE * pFichier;
    pFichier = fopen(chemFichTemp, "w");
    list<Ligne>::iterator il;
    for (il=lignes.begin(); il!=lignes.end(); il++){
        fputs(*il.toString(), pFichier);
    }
    fclose(pFichier);
}

void Buffer::majDom(){
    dom = Dom(chemFichTemp);
}

ostream& operator<<(ostream &os, const Buffer &b){
    b.affiche(os);
    return os;
}

istream& operator>>(istream &is, Buffer &b){
    b.saisie(is);
    return is;
}




