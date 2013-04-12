#ifndef DEF_FACTEUR
#define DEF_FACTEUR

class Facteur {

	private:
		char* texte;
		char* couleur;
		char* texteFormate;

	public:
		Facteur(char* text);
		~Facteur();
		void setTexte(char* text);
		char* getTexte();
		char* getTexteFormate();
		void setCouleur (char* color);
		void formate();
};

#endif
