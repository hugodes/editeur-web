// La classe ligne.cc

#include"ligne.h"
#include"facteur.h"
#include<vector>

Ligne::Ligne() {}

Ligne::~Ligne() {}

Ligne::Ligne(vector<Facteur> t)
{

	int i=0;
    this->identUtil=0;
    this->text=t.text(); 				// text() est une méthode de la classe Facteur qui nous retourne une chaine de caractères

		     
    
    while ((this->text[i]) =='\t'){		  	//	-------> Calculer l'identation d'une ligne
		(this->identUtil)=(this->identUtil)+1;		
		i++;
	}
    
}

Ligne::Ligne(char *t[]) {
vector<Facteur> v;
vector<Facteur>::iterator iter=v.begin();

v=NULL;
int i=0;
 //vector<char> facteur;
char facteur[100];
 
this->identUtil=0;
//-----------------------> Calcule identation d'une ligne <-------------------------->
	while (*t[i] =='\t'){                               
		(this->identUtil)=(this->identUtil)+1; 	   
		v.push_back(*t[i]);			  
		i++;					 	
	}
//------------------------------------------------------------------------------------>
//Extraire l'ensemble des facteurs qui forment une ligne ----------------------------->

	while (t[i] != '\0')
	{
		memset (facteur, 0, sizeof (facteur));
		while ((*t[i]) !=' '){
			strcat(facteur, (t[i]));
			i++;			
				}
				
				v.push_back(facteur);
				v.push_back(' ');
		i++;
	}
	
}


