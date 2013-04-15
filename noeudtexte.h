#ifndef domtext_h
#define domtext_h

#include <string>

using namespace std;

//#include <vector>

class Noeud;
class DOMText : public Noeud{

private :
    string text;

public :
	DOMText ();
	~DOMText();
	DOMText(string);
};


#endif
