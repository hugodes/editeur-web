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

vector<Facteur>::iterator i=t.begin();

    this->indentUtil=0;
    this->ligne=t; 	
    char* tab="\t";	

	while (strcmp (((*i).getTexte),tab)==0)
	{		  	
		(this->indentUtil)++;		
		i++;
	}
    
}

/* Constructeur Parametré */
Ligne::Ligne(char* t){
	
	Facteur fact;
	int i=0;
	char f[100];
	char espace=' ';
	char f_ligne= '\0';  
	char* tab="\t";	
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

	while (t[i] != '\0')
	{
	memset (f, 0, sizeof (f));  // vider le tableau f

		while ((t[i]) !=' ')
				{
			strcat(f, (t[i]));
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

char* ligne::toString(){
	vector<Facteur>::iterator i;
	char* l;

	for(i=ligne.begin(); i<(ligne.size()); i++){
	strcat(l, *i);	
	i++;
	}

return l;	
}
	return (this->ligne);
}

void ligne::affiche(ostream& os){
vector<Facteur>::iterator i;

for (i=this->ligne.begin(); i<ligne.end(); i++){
	os<<(*i).getTexte();
	}

}
 

ostream& operator << (ostream & os, const Ligne &o){
	o.affiche(os);
	return os;
}

