CC=g++
OBJECTS= facteur.o ligne.o buffer.o dom.o leedit.o main.o noeud.o noeudtexte.o test.o
OBJECTSH= facteur.h ligne.h buffer.h dom.h noeud.h noeudtexte.h


leedit	: $(OBJECTS)
	$(CC) $(OBJECTS) -o leedit

test : $(OBJECTS)
	$(CC) $(OBJETCS) -o test

test.o : test.cc $(OBJECTSH)
	$(CC) -c test.cc

facteur.o : facteur.cc facteur.h
	$(CC) -c facteur.cc

ligne.o : ligne.cc ligne.h
	$(CC) -c ligne.cc

buffer.o : buffer.cc buffer.h
	$(CC) -c buffer.cc

dom.o : dom.cc dom.h 
	$(CC) -c dom.cc

noeud.o : noeud.cc noeud.h
	$(CC) -c noeud.cc

noeudtexte.o : noeudtexte.cc noeudtexte.h
	$(CC) -c noeudtexte.cc	

clean :
	rm -f *~ *.o leedit test