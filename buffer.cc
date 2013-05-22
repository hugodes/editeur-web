/**
 * @file buffer.cc
 * @author Hugo des Longchamps
 * @class Buffer
 * @details Surcharge des operateurs << & >>
 */

#include "buffer.h"

Buffer::Buffer(){
    lignes = list<Ligne>();
    string s = ".nouveau_fichier.tmp";
    chemFichTemp=new char[s.length()+1];
    strcpy(chemFichTemp, s.c_str());
}

Buffer::Buffer(char cheminFichier[]){
    lignes = list<Ligne>();
    dom = Dom(lignes);
    setLignes(cheminFichier);
    char *s=new char[sizeof(char)*2];
    strcpy(s, ".");
    chemFichTemp = strcat(s, cheminFichier);
    chemFichTemp = strcat(cheminFichier, ".tmp");
}

Buffer::~Buffer(){
    delete chemFichTemp;
}

void Buffer::ajouterLigne(Ligne l, int position){
    list<Ligne>::iterator il = lignes.begin();
    advance(il,position-1);
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
    //  char *buffer=new char[sizeof(char)*1024];
    Ligne L;
    pFichier =  fopen(cheminFichier, "r");
    if (!pFichier){
        cout<<"Le fichier avec lequel vous essayez de remplir les lignes du buffer n'existe pas"<<endl;
    }
    else{
      yyin = pFichier;
      int i;
      int jeton;
      Facteur (*F);
      while((i = yylex()) != 0){
	switch(i){
	case ATTRIBUT :
	  if(jeton == 331){
	    F = new Facteur(yytext, i);
	    L.push_back(*F);
	  }
	  else{
	    int k = STRING;
	    F = new Facteur(yytext, k);
	    L.push_back(*F);
	    jeton = i;
	  }
	  break;
	
	case SPACE :
	  if(jeton == 331){
	    F = new Facteur(yytext, i);
	    L.push_back(*F);
	  }
	  else{
	    F = new Facteur(yytext, i);
	    L.push_back(*F);
	    jeton = i;
	  }
	  break;

	case BALISEFERMANTE :
	  F = new Facteur(yytext, i);
	  L.push_back(*F);
	  jeton = i;
	  break;
	  

	case ENDL : 
	  F = new Facteur(yytext, i);
	  L.push_back(*F);
	  lignes.push_back(L);
	  L.clear();
	  jeton = i;
	  break;
		
	default :
          F = new Facteur(yytext, i);
          L.push_back(*F);
	  jeton = i;
	  break;
	}
	delete F;
      }
    }
    fclose(pFichier);
    sauvTemp();
    majDom();
}


void Buffer::affiche(ostream & os)const{
    list<Ligne>::const_iterator il;
    vector<Facteur>::const_iterator iv;
    cout<<"taille de lignes: "<<lignes.size()<<endl;
    for (il=lignes.begin(); il!=lignes.end(); il++){
        for(iv=(*il).begin(); iv!=(*il).end(); il++){
            os<<(*iv).getTexteFormate();
        }
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
    vector<Facteur>::const_iterator iv;
    list<Ligne>::iterator il;
    for (il=lignes.begin(); il!=lignes.end(); il++){
        for(iv=(*il).begin(); iv!=(*il).end(); il++){
            fputs((*iv).getTexte(), pFichier);
        }
    }
    fclose(pFichier);
}

void Buffer::majDom(){
    dom = Dom(lignes);
}

ostream& operator<<(ostream &os, const Buffer &b){
    b.affiche(os);
    return os;
}

istream& operator>>(istream &is, Buffer &b){
    b.saisie(is);
    return is;
}




