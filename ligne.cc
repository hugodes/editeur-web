//Créateur: Amazigh Haddadou

#include"ligne.h"
#include"facteur.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

/* Constructeur par defaut de Ligne */
Ligne::Ligne(){
this->ligne=vector<Facteur>();
this->indentUtil=0;
}

/* Destructeur de Ligne */
Ligne::~Ligne() {}

/* Constructeur Parametré */
Ligne::Ligne(vector<Facteur> t){

vector<Facteur>::iterator iter;
	
	this->indentUtil=0;
	this->ligne=t; 	
	char* tab;
	tab=new char[3];
	strcpy(tab, "\t");	
	int i=0;

	while (strcmp ((iter[i].getTexte()),tab)==0)
	{		  	
		(this->indentUtil)++;		
		i++;
	}
    
}

/* Constructeur Parametré */

Ligne::Ligne(const char* t){
	
	Facteur fact;
	int i=0;
	char f[100];

	char* espace;
	espace=new char[2];
	strcpy(espace," ");
	
	char* f_ligne;  
	f_ligne=new char[3];
	strcpy(f_ligne, " ");

	char* tab;
	tab=new char[3];
	strcpy(tab, "\t");
	
	this->indentUtil=0;
//-----------------------> Calcule indentation d'une ligne <--------------------------//
	while (t[i] =='\t')
	{                               
		(this->indentUtil)++;
		fact.setTexte(tab); 	   
		ligne.push_back(fact);		  
		i++;					 	
	}

//------------------Extraire l'ensemble des facteurs qui forment une ligne ----------------------------->

	while (t[i] !='\0')
	{
	memset (f, 0, sizeof (f));  // vider le tableau f

		while ((t[i]) !=' ')
				{
			strcat(f,const t[i]);
			i++;			
				}
	fact.setTexte(f);
	this->ligne.push_back(fact);
	fact.setTexte(espace);
	this->ligne.push_back(fact);
	i++;
	}
fact.setTexte(f_ligne);
this->ligne.push_back(fact);
}


char* Ligne::toString(){
	vector<Facteur>::iterator iter;
	char* l;

	for (int i=0; i<ligne.size(); i++){
		strcat(l, iter[i].getTexte());
	}

return l;	
}


void Ligne::affiche(ostream &os)const {
vector<Facteur>::iterator iter;

for (int ii=0; ii<ligne.size(); ii++){
	os<<(iter[ii].getTexte());
	}

}
 

ostream& operator << (ostream & os, const Ligne &o){
	o.affiche(os);
	return os;
}

