CC=g++
OBJECTS= .tmp/facteur.o .tmp/buffer.o .tmp/dom.o .tmp/leedit.o .tmp/main.o .tmp/noeud.o .tmp/noeudtexte.o .tmp/test.o
OBJTEST= .tmp/facteur.o .tmp/buffer.o .tmp/dom.o .tmp/noeud.o .tmp/test.o .tmp/noeudtexte.o



leedit	: $(OBJECTS)
	$(CC) $(OBJECTS) -o leedit

test : $(OBJTEST)
	$(CC) -o test $(OBJTEST)

.tmp/lex.yy.c : scripts/analyse.lex
	flex -o .tmp/lex.yy.c scripts/analyse.lex

.tmp/test.o : tests/test.cc
	$(CC) -c tests/test.cc -o .tmp/test.o

.tmp/facteur.o : source/core/facteur.cc headers/core/facteur.h
	$(CC) -c source/core/facteur.cc -o .tmp/facteur.o

.tmp/buffer.o : source/core/buffer.cc headers/core/buffer.h .tmp/lex.yy.c
	$(CC) -c source/core/buffer.cc -o .tmp/buffer.o

.tmp/dom.o : source/core/dom.cc headers/core/dom.h
	$(CC) -c source/core/dom.cc -o .tmp/dom.o

.tmp/noeud.o : source/core/noeud.cc headers/core/noeud.h
	$(CC) -c source/core/noeud.cc -o .tmp/noeud.o

.tmp/noeudtexte.o : source/core/noeudtexte.cc headers/core/noeudtexte.h
	$(CC) -c source/core/noeudtexte.cc -o .tmp/noeudtexte.o

doc : scripts/Doxyfile
	doxygen scripts/Doxyfile

clean :
	rm -f .tmp/*
