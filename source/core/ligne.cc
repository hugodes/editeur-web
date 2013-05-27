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
 * @brief Constructeur par copie
 */
Ligne::Ligne(const Ligne& l){
    indentUtil=l.indentUtil;
    if(!(ligne.empty())){
        ligne.clear();
    }
    indentUtil=l.indentUtil;
    vector<Facteur>::iterator i=ligne.begin();
    for(i;i<ligne.end();i++){
        ligne.push_back(*i);
    }
}

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
     
	
    while ((strcmp ((*i).getTexte(),tab)==0)&&(i<v.end()))
    {
        (this->indentUtil)++;
        i++;
    }

}

/**
* @brief Constructeur de ligne // à supprimer lors de l'implementation de l'analyseur
*/

Ligne::Ligne(char*& t){
	Facteur fact;
	int i=0;
	char f[100];  // un tableau qui va contenir les caractères pour former un Facteur
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
		fact=Facteur(tab); 	   
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
			fact= Facteur(f);
			//fact.setTexte(f);
	  		ligne.push_back(fact);
	  		fact.setTexte(f_ligne);
	  		ligne.push_back(fact);
			}
		else{
			fact= Facteur(f);
			//fact.setTexte(f);
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
char* Ligne::toCString(){ 

	vector<Facteur>::iterator iter=ligne.begin();
	char *l;
	int taille_l=0;

	for (iter=(ligne.begin()); iter<ligne.end(); iter++){
	taille_l=taille_l+((*iter).taille());
	}

        l=new char[taille_l+1];
	strcpy(l," ");

	for (iter=(ligne.begin()); iter<ligne.end(); iter++){
		strcat(l, ((*iter).getTexte()));
	}
return l;
	
}

/**
* @brief Retourne une ligne
* @brief Retourne une ligne
*/
string Ligne::toString(){ 
                
        vector<Facteur>::iterator iter=ligne.begin();
        char *l;
        int taille_l=0;

        for (iter=(ligne.begin()); iter<ligne.end(); iter++){
        taille_l=taille_l+((*iter).taille());
        }

        l=new char[taille_l+1];
        strcpy(l," ");

        for (iter=(ligne.begin()); iter<ligne.end(); iter++){
                strcat(l, ((*iter).getTexte()));
        }
string li(l);
delete l;
return li;  
     
}


/**
* @brief Retourne le d'une ligne
*/

void Ligne::affiche(ostream &os) const{
vector<Facteur>::const_iterator iter;

for (iter=((this->ligne).begin()); iter<(this->ligne.end()); iter++){
	os<<(string((*iter).getTexte()));
	}
	os<<"\nl'indentation de la ligne est "<<(this->indentUtil)<<endl;

}

/**
 * @brief Surcharge de l'operateur =
 * @return L'instance de l'objet copié
 */

/*
 * en travaux
Ligne& Ligne::operator=(const Ligne& l){
    indentUtil=l.indentUtil;

    if(!(ligne.empty())){
        ligne.clear();
    vector<Facteur>::iterator i=((l.ligne).begin());
    for(i;i<((l.ligne).end());i++){
        ligne.push_back(*i);
    }
    return *this;
}

*/
/**
* @brief Surcharge de l'operateur <<
* @return Retourne le flux de sortie  
*/
ostream& operator << (ostream & os, const Ligne &o){
	o.affiche(os);
	return os;
}

