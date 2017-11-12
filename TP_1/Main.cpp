#include "Arbre.cpp"

#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
	cout << "Initialisation de l'arbre" << endl ;
	arbre A ;

	A.fabrique("+ 2 3") ;

	return 0 ;
}