#include "Tableau.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

int C(string K)		//return le nombre de lettre différente
{
	string spe("");
	int sol=0;
	for(int i=0; i<sizeof(K) ; i++)		// K.lenght()
	{
		int k=0;
		while(K[i]!=spe[k] && k<sizeof(K))
		{
			k++;
		}
		if(K[i]!=spe[k])
		{
			sol++;
			spe=spe + K[i];
		}
	}
	return sol ;
}

int hachage(string K)
{
	//H(Mot)=(∑Mot.length()(Mot[i]−'A')∗Bi)%N
	int nb=0;
	for(int i=0; i<sizeof(K);i++)	
	{
		nb+=(K[i]-1)*C(K);
	}
	return nb%B ;
}

template<typename T>
void remplir()
{
	tableahachage<T> A_table(10) ;
	fstream fichier ;
	fichier.open("mots.txt", ios::in) ;

	if(fichier)
	{ 
		T info ;
		fichier >> info ;
		while(!fichier.eof())
		{
			int x = hachage(info) ;
			//cout << x << endl ;
			A_table.insertion(x,info) ;
			fichier >> info ;
		}

		fichier.close() ;
	}
	A_table.afficher() ;
}