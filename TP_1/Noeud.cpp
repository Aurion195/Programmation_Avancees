#include "Arbre.h"

#include <iostream>

using namespace std ;

noeud * NN_Operateur(char b, noeud * x, noeud * y)
{
	noeud * tmp = new noeud ;

	if(b == '+' || b == '-' || b == '*' || b == '/' || b == '_') 
	{
		tmp->ope = b ;
		tmp->var = (char)NULL ;
		tmp->val = 0 ;
		tmp->exposant = 0 ;
		tmp->type = (char*)"Operateur" ;

		tmp->fg = x ;
		
		if(b != '_')
		{
			tmp->fd = y ;
		}
		else tmp->fd = NULL ;
		
	}
	else
	{
		cerr << "Erreur, opérateur non connu" << endl ;
		return tmp ; 
	} 
}

noeud * NN_Variable(char a)
{
	noeud * tmp = new noeud ;

	if(a == 'X' || a == 'Y' || a == 'Z')
	{
		tmp->ope = (char)NULL ;
		tmp->var = a ;
		tmp->val = 0 ;
		tmp->exposant = 0 ;
		tmp->type = (char*)"Variable" ;

		tmp->fg = NULL ;
		tmp->fd = NULL ;
	}
	else
	{
		cerr << "Erreur : Variable inconnue" << endl ;
		return tmp ;
	}
}

noeud * NN_Valeur(double y)
{
	noeud * tmp = new noeud ;

	tmp->ope = (char)NULL ;
	tmp->var = (char)NULL ;
	tmp->val = y ;
	tmp->exposant = 0 ;
	tmp->type = (char*)"Valeur" ;

	tmp->fg = NULL ;
	tmp->fd = NULL ;

	return tmp ;
}

noeud * NN_Exposant(char expo, int z, noeud * x, noeud * y)
{
	noeud * tmp = new noeud ;

	if(expo == '^')
	{
		tmp->ope = '^' ;
		tmp->var = (char)NULL ;
		tmp->val = 0 ;
		tmp->exposant = z ;
		tmp->type = (char*)"Exposant" ;

		tmp->fg = x ;
		tmp->fd = y ;
	}
	else
	{
		cerr << "Erreur : Operateur inconnu" << endl ;
		return tmp ;
	}
}