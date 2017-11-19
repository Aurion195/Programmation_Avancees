#include "Noeud.cpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

Arbre::Arbre()
{
	root = NN('/',NULL,0) ;
}

Arbre::~Arbre()
{
	if(root) del(root) ;
}

void Arbre::del(noeud * r)
{
	if(r == NULL) return ;
	else
	{
		del(r->fg) ;
		del(r->frd) ;
	}

	delete [] r ;
}

void Arbre::afficher()
{
	if(root)
	{
		print(root->fg) ;
	}
}

void Arbre::print(noeud * r)
{
	if(r == NULL) return ;
	else
	{
		cout << r->info ;

		print(r->fg) ;
		//cout << r->info ;
		print(r->frd) ;
		if(r->fg == NULL) cout << "	Nb lettres : " << r->x << "	|	Nb occurences : " << r->occ << endl ;
	}
}

void Arbre::fabrique(string nom_fichier)
{
	ifstream fichier("Essai.txt", ios::in);				//Ouvre le fichier demandé

	if(fichier)
	{
		noeud * save = NULL ;
		int max = 0 ;
		string ligne ;
		while(getline(fichier, ligne))
		{
			if(!trouve(ligne, root, save, max))					//Analyse le tableau et revoi faux si le mot n'y est pas
			{											//si le mot y est on incrémente son pointeur de fin de 1
				Creation(ligne, root, 1) ;				//Permet de créer les mot
			}
		}

		fichier.close() ;								//Ferme le fichier ouvert
	}
}

void Arbre::Creation(string ligne, noeud * r, int valeur)
{
	if(ligne[0] == '\0') return ;
	else
	{
		if(r->fg == NULL)
		{
			while(ligne[0] != '\0')						//Si le fg d'un noeud est null on utilise un while
			{											//pour créer tous les noeuds
				r->fg = NN(ligne[0],r,valeur) ;
				ligne.erase(ligne.begin()) ;			//Efface le début du mot
				r = r->fg ;
				valeur += 1 ;							//Incrémente le compteur de lettre
			}

			return ;
		}
		else
		{
			r = r->fg ;									//Le fg est pas nul on va dedans
			if(r->info == ligne[0])						//Si le fg correnspont à la 1er lettre on va dedans
			{
				ligne.erase(ligne.begin()) ;
				Creation(ligne, r,valeur+1) ;
			}
			else
			{
				while(r && r->frd)						//Tant que le frd est différent de nul on recherhce
				{
					if(r->info == ligne[0])				//Si ça correspond on renvoi la fonction
					{
						ligne.erase(ligne.begin()) ;
						Creation(ligne, r->frd,valeur+1) ;
					}

					r = r->frd ;
				}


				r->frd = NN(ligne[0],r->pere,valeur) ;			//Le noeud contenant le caractere n'existe pas,
				ligne.erase(ligne.begin()) ;			//on le crée donc
				Creation(ligne,r->frd,valeur+1) ;
			}
		}
	}
}

bool Arbre::trouve(string ligne, noeud * r, noeud * &save, int& max)				//Permet de trouver un mot dans l'arbre
{
	if(r->fg == NULL) return false ;					//Si root == NULL, on renvoi faux
	else
	{
		r = r->fg ;										//On va dans le fg

		while(r != NULL)								//Tant que le noeud est != NULL
		{
			if(r->info == ligne[0])						//si le 1er noeud correspond on va dedans
			{											//on efface le 1er caractere
				r = r->fg ;
				ligne.erase(ligne.begin()) ;

				if(r->fg == NULL)						//si c'est le dernier caractere
				{										//on augmente son nombre d'occurences
					r->occ += 1 ;
					return true ;
				}
			}
			else if(r->frd != NULL)						//Si il est pas dans le fg on regarde ses frd
			{
				while(r && r->frd)
				{
					if(r->info == ligne[0])
					{
						ligne.erase(ligne.begin()) ;
					}

					r = r->frd ;
				}
			}
			else										//Le mot n'est pas dedans, on eut l'ajouter dans l'arbre
			{
				return false ;
			}
		}
	}
}