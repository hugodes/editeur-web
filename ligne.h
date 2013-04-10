// la classe ligne.h

#ifndef DEF_LIGNE
#define DEF_LIGNE
#include<vector>
#include"facteur.h"

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
};


#endif

