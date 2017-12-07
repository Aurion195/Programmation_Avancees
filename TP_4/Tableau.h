#include <iostream>
#include <string>

using namespace std ;

const int taille = 5 ;

template <typename T>
class maillon
{
	friend class liste ;
	int cpt ;
	T valeur ;
	maillon <T> * suiv ;

	maillon()
	{
		cpt = 0 ;
		//valeur = NULL ;
		suiv = NULL ;
	}
} ;

template <typename T>
class liste
{

	maillon <T> * tete ;
	maillon <T> * queu ;

	public:
		liste()
		{
			tete = queu = NULL ;
		}
} ;

template <typename T>
class tableahachage
{
	liste<T> * tab ;

	public:
		tableahachage()
		{
			tab = new liste<T>[taille] ;
		}
} ;