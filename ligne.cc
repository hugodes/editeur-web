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
    this->text=t.getText();		     
//-----------------------> Calcule indentation d'une ligne <-------------------------->
    while ((this->text[i]) =='\t'){		  	
		(this->indentUtil)=(this->indentUtil)+1;		
		i++;
	}
    
}

Ligne::Ligne(char *t[]) {
vector<Facteur> v;


v=NULL;
int i=0;
char f[100]; 
string facteur;
 
this->indentUtil=0;
//-----------------------> Calcule indentation d'une ligne <-------------------------->
	while (*t[i] =='\t'){                               
		(this->indentUtil)=(this->indentUtil)+1; 	   
		v.push_back(*t[i]);			  
		i++;					 	
	}
//------------------------------------------------------------------------------------------------------>
//------------------Extraire l'ensemble des facteurs qui forment une ligne ----------------------------->

	while (t[i] != '\0')
	{
		memset (f, 0, sizeof (f));  // vider le tableau f
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
string toString (){
	return (this->text);
}

