#include <stdlib.h>
#include <stdio.h>

int min(int* tab ,int taille)
{
	int i;
	int min = tab[0];

	for(i = 0;i<taille ;i++)
	{

		if (tab[i]<min)
		min = tab[i];

	}
	

	return min ;

}





int* creer_tableau(int taille)
{
 int* tab = (int*)malloc(taille*(sizeof(int)));

	return tab;
}


int* supprimer_valeur_tableau(int* tab,int valeur,int taille)
{
	int* resultat = creer_tableau(taille-1);
	int marqueur =0;

	int i,j = 0;
	
	for(i=0;i<taille;i++)
	{

		if(tab[i] == valeur && marqueur == 0)
		{
			marqueur = 1;
			continue;

		}
		else
		{
		
			
			resultat[j] = tab[i];
			j++;
		}

	}

	return resultat;
}


void afficher_tableau(int* tab,int taille)
{
	int i;

	for (i =0;i<taille;i++)
	{

		printf("%d ",tab[i]);
	}



}

int* trier_tableau(int* tab,int taille)
{
        int tableau[taille];
	int i = 0;
	while(i<taille)
	{
	//printf("\n");
	//afficher_tableau(tab,taille-i);	
        int a = min(tab,taille-i);
	//printf("%d\n",a);

	tableau[i] = a;
	tab = supprimer_valeur_tableau(tab,a,10);
	i++;
	//printf("\n");
	//afficher_tableau(tab,taille-i);
	}



	afficher_tableau(tableau,taille);
	return tab;

	


}

int main()
{
	//Ici on veut trier notre tableau dans l'ordre croissant
	int taille = 10;   
	int* tab = creer_tableau(taille);
	tab[0] = 2;
	tab[1] = 6;
	tab[2] = 54;
	tab[3] = 72;
	tab[4] = 7;
	tab[5] = 1;
	tab[6] = 2 ;
	tab[7] = 5;
	tab[8] = 53;
	tab[9] =118;

		
	printf("Le tableau de base(non trie) est le suivant:\n");
	afficher_tableau(tab,taille);
	printf("\n\nLe tableau trie est le suivant:\n");
	tab = trier_tableau(tab,taille);




}

	
	

	 

		
	

	


	










	




