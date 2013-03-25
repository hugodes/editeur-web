// la classe ligne.h

#ifndef LIGNE
#define LIGNE
using namespace std;
#include<vector>
#include"facteur.h"

class Ligne
{
private:
  int identUtil;
  vector<Facteur> text;

public:
	Ligne();
	~Ligne();
	Ligne(vector<Facteur> );
};

#endif

