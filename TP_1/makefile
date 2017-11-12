Calculatrice : Main.cpp Arbre.o Noeud.o
	g++ -std=c++11 Main.cpp -o Calculatrice

Arbre.o : Arbre.cpp Arbre.h
	g++ -std=c++11 -c Arbre.cpp -o Arbre.o

Noeud.o : Noeud.cpp Arbre.h
	g++ -std=c++11 -c Noeud.cpp -o Noeud.o

.PHONY clean :
	rm *.o Calculatrice