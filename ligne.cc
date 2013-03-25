// La classe ligne.cc

#include"ligne.h"
#include"facteur.h"
#include<vector>

Ligne::Ligne() {}

Ligne::~Ligne() {}

Ligne::Ligne(vector<Facteur> t)
{
    vector<Facteur>::iterator i;

    this.identUtil=0;
    this.text=t;

   for(i=t.begin(); i<t.end(); i++ )
   {
        if ((*i)==('\t'))
            this.iendtUtil++;
    }
}


