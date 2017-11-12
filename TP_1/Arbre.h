#ifndef DEF_ARBRE_H
#define DEF_ARBRE_H

#include <iostream>

struct noeud
{
	char ope ;
	char var ;
	double val ;
	int exposant ;
	char * type ;

	noeud * fg ;
	noeud * fd ;
} ;

class arbre 
{
	noeud * root ;

	public :
		arbre() ;
		~arbre() ;
		void fabrique(std::string x) ;
		void sup(noeud * tmp) ;
} ;
#endif