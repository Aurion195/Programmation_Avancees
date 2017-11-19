ArbreLex : Main.cpp Noeud.o Arbre.o
	g++ Main.cpp -o ArbreLex

Arbre.o : ArbreLex.cpp ArbreLex.h
	g++ -c ArbreLex.cpp -o Arbre.o

Noeud.o : Noeud.cpp ArbreLex.h
	g++ -c Noeud.cpp -o Noeud.o

clean : 
	rm * .o