/**
* @file ligne.cc
* @author  Amazigh Haddadou
* @classe Ligne ligne.h "./ligne.h"
*/

#include"ligne.h"
#include"facteur.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;
/**
* @brief Constructeur par defaut de Ligne 
*/
Ligne::Ligne(){
this->ligne=vector<Facteur>();
this->indentUtil=0;
}
/**
* @brief Destructeur de Ligne 
*/
Ligne::~Ligne() {}

/**
* @brief Constructeur de ligne
* @param t Vecteur de facteur
*/

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

/**
* @brief Constructeur de ligne
*/

Ligne::Ligne(const char* t){
	
	Facteur fact;
	int i=0;
	char f[100];

	char* espace;
	espace=new char[2];
	strcpy(espace," ");
	
	char* f_ligne;  
	f_ligne=new char[3];
	strcpy(f_ligne, "\0");

	char* tab;
	tab=new char[3];
	strcpy(tab, "\t");
	
	this->indentUtil=0;

	while (t[i] =='\t')
	{                               
		(this->indentUtil)++;
		fact.setTexte(tab); 	   
		ligne.push_back(fact);		  
		i++;					 	
	}



	while (t[i] !='\0')
	{
	memset (f, 0, sizeof (f));  

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

/**
* @brief Retourne une ligne
* @return Retourne une ligne
*/
char* Ligne::toString(){
	vector<Facteur>::iterator iter;
	char* l;

	for (int i=0; i<ligne.size(); i++){
		strcat(l, iter[i].getTexte());
	}

return l;	
}

/**
* @brief Retourne le d'une ligne
*/

void Ligne::affiche(ostream &os)const {
vector<Facteur>::iterator iter;

for (int ii=0; ii<ligne.size(); ii++){
	os<<(iter[ii].getTexte());
	}

}
/**
* @brief Surcharge de l'operateur <<
* @return Retourne le flux de sortie  
*/
ostream& operator << (ostream & os, const Ligne &o){
	o.affiche(os);
	return os;
}

