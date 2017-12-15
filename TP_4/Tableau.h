#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

const int B = 26 ;								//Nombre de lettres dans l'alphabet

template <typename T>
class liste ;

template <typename T>
class maillon
{
public:
	friend class liste<T> ;
	int cpt ;
	T valeur ;
	maillon <T> * suiv ;

	maillon(T info)
	{
		cpt = 1 ;
		valeur = info ;
		suiv = NULL ;
	}
} ;

template <typename T>
class liste
{
public:
	maillon <T> * tete ;
	maillon <T> * queu ;

		liste()
		{
			tete = queu = NULL ;
		}

		void insertionqueu(T info)
		{
			//cout << "3" << endl ;
			maillon <T> * x = new maillon<T>(info) ;

			if(tete == NULL)
			{	
				tete = x ;
				queu = x ;
				tete->suiv = queu ;
			}

			queu->suiv = x ;
			x->cpt += queu->cpt ;
			queu = x;
			queu->suiv = NULL ;
			

		}

		void aff()
		{
			maillon<T> * tmp = tete ;
				
				while(tmp)
				{
					cout << tmp->valeur << " / " ;
					if(tmp->suiv == NULL)
					{
						cout << endl << "Le nombre de collision est de : " << tmp->cpt ;
					} 
					tmp = tmp->suiv ;
				}
		}
} ;

template <typename T>
class tableahachage
{
	liste<T> *tab ;
	int taille ;

	public:
		tableahachage(int N)
		{
			taille = N ;
			tab = new liste<T> [taille] ;
		}

		void insertion(int x, T info)
		{
			//cout << "1" << endl ;
			for(int i = 0 ; i < taille ; i++)
			{
				if(i == x)
				{
					tab[x].insertionqueu(info) ;
				}
			}
		}

		void afficher()
		{
			for(int i = 0 ; i < taille ; i++)
			{
				cout << i << "		|	" ;
				tab[i].aff() ;
				cout << endl ;
			}
		}

}	 ;