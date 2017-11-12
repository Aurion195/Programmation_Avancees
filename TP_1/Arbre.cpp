#include "Arbre.h"
#include "Noeud.cpp"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std ;

arbre::arbre()
{
	root = NULL ;
}

arbre::~arbre()
{
	if(root)
	{	
		sup(root) ;
		delete [] root ;
	}
}

void arbre::sup(noeud * tmp)
{
	if(tmp == NULL) return ;
	else
	{
		sup(tmp->fg) ;
		sup(tmp->fd) ;
	}

	delete [] tmp ;
}

void arbre::fabrique(string ligne)
{
	if(ligne[0] == '\0') return ;
	else
	{
		noeud * N ;

		if(ligne[0] == '+' || ligne[0] == '-' || ligne[0] == '*' || ligne[0] == '/' || ligne[0] == '^' || ligne[0] == '_')
		{
			char l = ligne[0] ;
			N = NN_Operateur(l,NULL,NULL) ;
		}
		else if(ligne[0] == 'X' || ligne[0] == 'Y' || ligne[0] == 'Z')
		{
			char l = ligne[0] ;
			N->fd = NN_Variable(l) ;
		}
		else if(ligne[0] == ' ')
		{
			ligne.erase(ligne.begin()) ;
			fabrique(ligne) ;
		}
		else
		{
			double x = stod(ligne.substr(0)) ;
			cout << x << endl ;
		}

		ligne.erase(ligne.begin()) ;
		fabrique(ligne) ;
	}
}

void arbre::afficher()
{
	print(root) ;
}

void arbre::print(noeud * r)
{
	if(r == NULL) return ;
	else
	{
		if(r->type == "Opérateur") cout << r->ope  ;
	}
}