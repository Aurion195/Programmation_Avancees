#include <fstream>
#include <string>

struct noeud 
{
	char info ;
	noeud * fg ;
	noeud * frd ;
	noeud * pere ;
	int x ;
	int occ ;
};

class Arbre 
{
	noeud * root ;
	std::string Tab[] ;			//Permet de compter le nombre de fois que le mot apparait

	public:
		Arbre() ;
		//Arbre(std::string) ;
		~Arbre() ;
		void del(noeud * r) ;
		void afficher() ;
		void print(noeud * r) ;
		void Afficher_pere(noeud * r) ;
		void fabrique(std::string ligne) ;
		void Creation(std::string ligne, noeud * r, int valeur) ;
		bool trouve(std::string ligne, noeud * r,noeud * &s, noeud *&z, int &max, int &max_occ) ;
};