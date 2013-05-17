CC=g++
OBJECTS= facteur.o buffer.o dom.o leedit.o main.o noeud.o noeudtexte.o test.o
OBJTEST= facteur.o buffer.o dom.o noeud.o test.o noeudtexte.o



leedit	: $(OBJECTS)
	$(CC) $(OBJECTS) -o leedit

test : $(OBJTEST)
	$(CC) -o test $(OBJTEST)

analyse :
	flex analyse.lex

test.o : test.cc
	$(CC) -c test.cc

facteur.o : facteur.cc facteur.h
	$(CC) -c facteur.cc

buffer.o : buffer.cc buffer.h
	$(CC) -c buffer.cc

dom.o : dom.cc dom.h
	$(CC) -c dom.cc

noeud.o : noeud.cc noeud.h
	$(CC) -c noeud.cc

noeudtexte.o : noeudtexte.cc noeudtexte.h
	$(CC) -c noeudtexte.cc

clean :
	rm -f *~ *.o \#*# leedit test
