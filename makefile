CC=g++
OBJECTS= facteur.o buffer.o dom.o leedit.o main.o noeud.o noeudtexte.o test.o
OBJTEST= facteur.o buffer.o dom.o noeud.o test.o noeudtexte.o



leedit	: $(OBJECTS)
	$(CC) $(OBJECTS) -o leedit

test : $(OBJTEST)
	$(CC) -o test $(OBJTEST)

lex.yy.c : analyse.lex
	flex analyse.lex

test.o : test.cc
	$(CC) -c test.cc

facteur.o : source/core/facteur.cc headers/core/facteur.h
	$(CC) -c source/core/facteur.cc

buffer.o : source/core/buffer.cc headers/core/buffer.h lex.yy.c
	$(CC) -c source/core/buffer.cc

dom.o : source/core/dom.cc headers/core/dom.h
	$(CC) -c source/core/dom.cc

noeud.o : source/core/noeud.cc headers/core/noeud.h
	$(CC) -c source/core/noeud.cc

noeudtexte.o : source/core/noeudtexte.cc headers/core/noeudtexte.h
	$(CC) -c source/core/noeudtexte.cc

clean :
	rm -f *~ *.o \#*# leedit test
