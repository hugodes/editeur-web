// La classe ligne.cc

#include"ligne.h"
#include"facteur.h"
#include<string>
#include<vector>
using namespace std;

/* Constructeur par defaut de Ligne */
Ligne::Ligne(){
this->ligne="";
this->indentUtil=0;
}

/* Destructeur de Ligne */
Ligne::~Ligne() {}

/* Constructeur Parametré */
Ligne::Ligne(vector<Facteur> t){

vector<Facteur>::iterator i=t.begin();

    this->indentUtil=0;
    this->ligne=t; 	
   
	while (((*i).getText()) =='\t')
	{		  	
		(this->indentUtil)++;		
		i++;
	}
    
}

/* Constructeur Parametré */
Ligne::Ligne(char* t)
{
	
	Facteur fact;
	int i=0;
	char f[100];  
	this->indentUtil=0;
//-----------------------> Calcule indentation d'une ligne <--------------------------//
	while (t[i] =='\t')
	{                               
		(this->indentUtil)++;
		fact.setText('\t'); 	   
		ligne.push_back(fact);		  
		i++;					 	
	}
//------------------------------------------------------------------------------------------------------>
//------------------Extraire l'ensemble des facteurs qui forment une ligne ----------------------------->

	while (t[i] != '\0')
	{
	memset (f, 0, sizeof (f));  // vider le tableau f

		while ((t[i]) !=' ')
				{
			strcat(f, (t[i]));
			i++;			
				}
	fact.setText(f);
	this->ligne.push_back(fact);
	fact.setText(' ');
	this->ligne.push_back(fact);
	i++
	}
}

string toString(){
	return (this->ligne);
}

