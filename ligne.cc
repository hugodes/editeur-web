// La classe ligne.cc

#include"ligne.h"
#include"facteur.h"
#include<string>
#include<vector>

Ligne::Ligne() {}

Ligne::~Ligne() {}

Ligne::Ligne(vector<Facteur> t)
{

	int i=0;
    this->identUtil=0;
    this->text=t.text(); 	//-------------------->text() est une méthode de la classe Facteur qui nous retourne une chaine de caractères

		     
//-----------------------> Calcule identation d'une ligne <-------------------------->
    while ((this->text[i]) =='\t'){		  	
		(this->identUtil)=(this->identUtil)+1;		
		i++;
	}
    
}

Ligne::Ligne(char *t[]) {
vector<Facteur> v;


v=NULL;
int i=0;
char f[100]; 
string facteur;
 
this->identUtil=0;
//-----------------------> Calcule identation d'une ligne <-------------------------->
	while (*t[i] =='\t'){                               
		(this->identUtil)=(this->identUtil)+1; 	   
		v.push_back(*t[i]);			  
		i++;					 	
	}
//------------------------------------------------------------------------------------------------------>
//------------------Extraire l'ensemble des facteurs qui forment une ligne ----------------------------->

	while (t[i] != '\0')
	{
		memset (f, 0, sizeof (f));
		while ((*t[i]) !=' '){
			strcat(f, (*t[i]));
			i++;			
				}
				facteur = f;
				v.push_back(facteur);
				v.push_back(' ');
		i++;
	}
	
}


