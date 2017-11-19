#include "ArbreLex.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

int main()
{
	cout << "------------ Initialisation de l'arbre ------------" << endl ;

	string P = "Petit.txt" ;
	Arbre Petit ;
	Petit.fabrique(P) ;

	Petit.afficher() ;
	cout << endl ;

	return 0 ;
}