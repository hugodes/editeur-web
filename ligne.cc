/**
* @file ligne.cc
* @author  Amazigh Haddadou
* @classe Ligne ligne.h "./ligne.h"
*/

#include"ligne.h"

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

Ligne::Ligne(vector<Facteur> v){

    this->indentUtil=0;
    this->ligne=v;
    char* tab;
    vector<Facteur>::iterator i=v.begin();

    tab=new char[2];
    strcpy(tab, "\t");
    
//test 
	cout<<" la valeur de la premiere valeur du vecteur est "<<(*i).getTexte()<<endl;
    while ((strcmp ((*i).getTexte(),tab)==0)&&(i<v.end()))
    {
        (this->indentUtil)++;
        i++;
    }

}

/**
* @brief Constructeur de ligne
*/

Ligne::Ligne(char* t){
	
	Facteur fact;
	int i=0;
	char f[100];
	char caractere[2];
		caractere[0]=' ';
		caractere[1]='\0';

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

	if (t[i]=='\0'){
		fact.setTexte(f_ligne);
		this->ligne.push_back(fact);
			}

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
	bool b=false;
	bool fin_l=false;

		while (((t[i]) !=' ')&&(!fin_l))
			{
			b=true;
			caractere[0]=t[i];
			strcat(f, caractere);
			i++;
			if (t[i]=='\0'){
				fin_l=true;
				}				
			}
	  if (b){
		if (fin_l){
			fact.setTexte(f);
	  		this->ligne.push_back(fact);
	  		fact.setTexte(f_ligne);
	  		this->ligne.push_back(fact);
			}
		else{
			fact.setTexte(f);
			this->ligne.push_back(fact);		
			fact.setTexte(espace);
			this->ligne.push_back(fact);
		 	i++;
			}		
	}else {
		if (fin_l){	
		fact.setTexte(espace);
		this->ligne.push_back(fact);
		fact.setTexte(f_ligne);
		this->ligne.push_back(f_ligne);
	     }else
		{
		fact.setTexte(espace);
		this->ligne.push_back(fact);
		i++;
		}
	}
}
delete espace;
delete f_ligne;
delete tab;
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

