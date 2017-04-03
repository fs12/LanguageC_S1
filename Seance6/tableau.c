#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0


int **allouerTableau(int NbL,int NbC)
{

	int** Tableau =(int**)malloc(NbL*(sizeof(int*)));


	int i;
	for(i=0;i<NbL;i++)
	{

		Tableau[i]=(int*)malloc(NbC*(sizeof(int)));
	}
		return Tableau;
	




}

//On libere l'espace memoire pris par le tableau
void detruireTableau(int **tab,int Nb_L)
	{
		int i;
		for(i=0;i<Nb_L;i++)
		{

			free(tab[i]);
		}

		free(tab);

	}


//On vérifie la bonne allocation du tableau
int testTableau(int **tab,int Nb_L,char* nomFonction)
{
	int marqueur = 0,i;
	
	if (tab == NULL)
	{
		marqueur = 1;
	}


	for(i=0;i<Nb_L;i++)
		{

			if(tab[i] == NULL)
			marqueur = 1;
		}

	if(marqueur != 0)
	return FALSE;

	else
	return TRUE;

		

	

}


//ON affiche notre tableau
void afficherTableau(int** tab,int NB_L,int NB_C)
{
	int i,j;
	for(i = 0;i<NB_L;i++)
	{

		for(j=0;j<NB_C;j++)
		{
			printf(" %d\t",tab[i][j]);
			

		}
			printf("\n");


	}

}




void remplirTableau(int** tab, int Nb_L ,int Nb_C)
	{
		
		int mult = Nb_L*Nb_C;
		int i;
		int alterne = 0;
		int colonne_debut = 0;
		int colonne_fin=Nb_C -1;
		int compteur = 1;
		int ligne = 0;
		int ligne_inverse = Nb_L-1;
		
		int alterne_colonne = 0;
		int ligne_debut_colonne = 1;
		int ligne_fin_colonne = Nb_L-1;
		int j;
		int colonne = Nb_C-1;
		int colonne_bis = 0;
		int change = 0;
		

		while(compteur<=mult)
		{if(change == 0)
			{if(alterne == 0)
			{for(i= colonne_debut ;i<=colonne_fin;i++)
				{
					tab[ligne][i] = compteur;
					compteur ++;
				}
			ligne++;
			colonne_fin--;
			alterne = 1;
			}
			else
			{
				for(i= colonne_fin ;i>=colonne_debut;i--)
				{
					tab[ligne_inverse][i] = compteur;
					compteur ++;
				}
				ligne_inverse--;
				colonne_debut++;
				alterne = 0;

			

			}
			change = 1;
			}
		
			else 
			{
			if(alterne_colonne==0)
			{
				for(j=ligne_debut_colonne ;j<=ligne_fin_colonne;j++)
				{
					tab[j][colonne]=compteur;
					compteur++;
				}
			colonne--;
			alterne_colonne = 1;
			ligne_fin_colonne--;


			}
			else
			{
				for(j=ligne_fin_colonne ;j>=ligne_debut_colonne;j--)
				{
					tab[j][colonne_bis]=compteur;
					compteur++;
				}
				colonne_bis++;
				alterne_colonne =0;
				ligne_debut_colonne++;

			}
			change =0;
			}

		}	
	}





int main()
{
//On alloue notre tableau
	int** tab = allouerTableau(10,10);
//On teste si notre tableau existe bien
	int nb = testTableau(tab,3,"faical");
	if(nb == 1)
	{
		printf("Le tableau existe\n");
	}
	else
	{
		printf("Le tableau n'existe pas\n");
	}






//On remplit notre tableau grace a la fonction suivante
	remplirTableau(tab,10,10);

//On affiche notre tableau
	afficherTableau(tab,10,10);


//On libre l'espace memoire

	detruireTableau(tab,4);
	int nb2 = testTableau(tab,4,"faical");
	if(nb2 == 1)
	{
		printf("Le tableau existe\n");
	}
	else
	{
		printf("Le tableau n'existe pas\n");
	}
	
		


	return 0;
}





















