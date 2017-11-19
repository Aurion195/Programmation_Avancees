#include "ArbreLex.h"

#include <iostream>

using namespace std ;

noeud * NN(char c, noeud * p, int y)				//Correspond à la valeur
{
	noeud * r = new noeud ;

	r->info = c ;
	r->fg = r->frd = NULL ;
	r->pere = p ;				//A l'addresse du mot le plus grand
	r->x += y ;							//Compte le nombre de lettre dans le mot (correspond a valeur dans Creation())
	r->occ = 1 ;						//Compte le nombre d'occurences dans le mot

	return r ;
}