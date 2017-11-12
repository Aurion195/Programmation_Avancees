struct noeud
{
	char * ope ;
	char * var ;
	double val ;
	int exposant ;
	char * type ;

	noeud * fg ;
	noeud * fd ;
} ;