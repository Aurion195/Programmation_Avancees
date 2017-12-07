#include "Tableau.h"

#include <iostream>
#include <string>

using namespace std ;

const int N = 5 ;

template <typename T>
T hachage(T mot, int taille,int B)
{
	int somme = 0 ;
	for(unsigned i = 0 ; i < taille ; i++)
	{
		somme += ((mot[i] - 'a') * (B*B) ) ;
	}

	return somme%taille ;
}

template <typename T>
void afficher(T * tab)
{
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < N ; j++)
		{
			cout << tab[i][j] ;
		}

		cout << endl ;
	}
}

int main()
{
	tableahachage<string> T ;


	return 0 ;
}