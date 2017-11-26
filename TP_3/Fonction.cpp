#include <iostream>
#include <cstring>

using namespace std ;

void afficher(string M[5][5])
{
	cout << "\n" << "\n" << "--------------------------------" << endl ;
	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 5 ; j++)
		{
			cout << M[i][j] << "	" ;
		}

		cout << endl ;
	}
}

bool acceptable(string M[5][5])
{
	for(int b = 0 ; b < 5 ; b++)
	{
		if((M[0][b] == "Rouge" || M[1][b] == "Anglais") && !(M[0][b] == "Rouge" && M[1][b] == "Anglais"))
		{	
			return false ;
		}
		else if((M[0][b] == "Blanc" || M[0][b]== "Vert") && !(M[0][b] == "Blanc" && M[0][b] == "Vert"))
		{
			return false ;		
		}
		else if((M[0][b] == "Vert" || M[2][b] == "Café") && !(M[0][b] == "Vert" && M[2][b] == "Café"))
		{
			return false ;
		}
		else if((M[3][b] == "Kool" || M[0][b] == "Jaune") && !(M[3][b] == "Kool" && M[0][b] == "Jaune"))
		{
			return false ;
		}
		else if((M[1][b] == "Urkr" || M[2][b] == "Thé") && !(M[1][b] == "Urkr" && M[2][b] == "Thé"))
		{
			return false ;
		}
		else if((M[4][b] == "Chien" || M[1][b] == "Esp") && !(M[4][b] == "Chien" && M[1][b] == "Esp"))
		{
			return false ;
		}
		else if((M[3][b] == "Old" || M[4][b] == "Esca") && !(M[3][b] == "Old" && M[4][b] == "Esca"))
		{
			return false ;
		}
		else if((M[3][b] == "Chest" ||  M[4][b] == "Renard") && !(M[3][b] == "Chest" &&  (M[4][b+1] == "Renard" || M[4][b-1] == "Renard")))
		{
			return false ;
		}
		else if((M[3][b] == "Kool" || M[4][b] == "Cheval") && !(M[3][b] == "Kool" && (M[4][b+1] == "Cheval" || M[4][b-1] == "Cheval")))
		{
			return false ;
		}
		else if((M[4][b] == "Gitane" || M[2][b] == "Vin") && !(M[3][b] == "Gitane" && M[2][b] == "Vin"))
		{
			return false ;
		}
		else if((M[4][b] == "Craven" || M[1][b] == "Japo") && !(M[4][b] == "Craven" && M[1][b] == "Japo"))
		{
			return false ;
		}
		else
		{
			cout << "Error : Mot inconnue !" << endl ;
			return false ;
		}
	}

	return true;
}

void BackTa(string M[5][5], int cpt, string Couleur[5], string Nationalite[5], string Boisson[4], string Fume[5], string Annimal[4])
{
	if(cpt == 5)
	{
		if(acceptable(M)) {
			afficher(M) ;
		}
		return;
	}
	for(int i = 0; i < 5; i++) 
	{
		M[0][cpt] = Couleur[i] ;

		for(int j = 0; j < 5; j++) 
		{
			M[1][cpt] = Nationalite[j] ;

			for(int k = 0 ; k < 5 ; k++)
			{
				M[2][cpt] = Boisson[k] ;

				for(int e = 0 ; e < 5 ; e++)
				{
					M[3][cpt] = Fume[e] ;

					for(int z = 0 ; z < 5 ; z++)
					{
						M[4][cpt] = Annimal[z] ;
						BackTa(M, cpt + 1, Couleur, Nationalite, Boisson, Fume, Annimal);
					}
				}
			}
		}
	}
}

void BackT(string M[5][5])
{
	//Création Tableau !
	string Couleur[5] = {"Rouge", "Blanc", "Vert", "Bleu", "Jaune"} ;
	string Nationalite[5] = {"Japo", "Norve", "Anglais", "Esp", "Urkr"} ;
	string Boisson[5] = {"Thé", "Vin", "Lait", "Café", "Eau"} ;
	string Fume[5] = {"Chest", "Old", "Kool", "Gitanes", "Craven"} ;
	string Annimal[5] = {"Chien", "Cheval", "Renard", "Esca", "Zebre"} ;
	BackTa(M, 0, Couleur, Nationalite, Boisson, Fume, Annimal);
}