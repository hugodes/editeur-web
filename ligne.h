//Créateur: Amazigh Haddadou 

#ifndef DEF_LIGNE
#define DEF_LIGNE
#include<vector>
#include"facteur.h"
#include<iostream>

class Ligne
{

	private:
  		int indentUtil;
  		vector<Facteur> ligne;

	public:
		Ligne();
		~Ligne();
		Ligne(vector<Facteur>);
		Ligne(char*);
		string toString();
		void affiche(ostream&)const;
};

ostream& operator <<(ostream &, const Ligne &);

#endif

