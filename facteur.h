#ifndef DEF_FACTEUR
#define DEF_FACTEUR

class facteur {

	private:
		char* texte;
		char* couleur;
		char* texteFormate;

	public:
		facteur(char* text);
		~facteur();
		void setTexte(char* text);
		char* getTexte();
		char* getTexteFormate();
		void setCouleur (char* color);
		void formate();
};

#endif
