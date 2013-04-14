
leedit	: facteur.o ligne.o buffer.o dom.o leedit.o main.o noeud.o noeudtexte.o
	g++ -o leedit facteur.o ligne.o buffer.o dom.o leedit.o main.o noeud.o noeudtexte.o

test : facteur.o test.o
	g++ -o test test.o facteur.o

test.o : test.cc
	g++ -c test.cc

facteur.o : facteur.cc facteur.h
	g++ -c facteur.cc
