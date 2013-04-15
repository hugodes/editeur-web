#ifndef domtext_h
#define domtext_h

#include <string>
#include "noeud.h"
using namespace std;

//#include <vector>


class DOMText : public Noeud{

private :
    string text;

public :
	DOMText ();
	~DOMText();
	DOMText(string);
};


#endif
