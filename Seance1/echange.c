#include <stdio.h>
#include<stdlib.h>

void echange(int* tab,int taille)
{
	int retour = taille-1;
	int i;
	int resultat[taille];
	int result;

	for(i=0;i<taille;i++)
	{
		
		resultat[i] = tab[retour];
		//printf("%d : %d \n",resultat[i],tab[retour]);
		retour--;


	}

	for(i=0;i<taille;i++)
	{
		
		
		//printf("%d ",tab[i]);
		
		


	}
		printf("\n");
	result = 0;

	for(i=0;i<taille-1;i++)
	{
		
		result=(result +(resultat[i]))*10;
		


	}
	result=(result+resultat[taille-1]);

	printf("%d \n",result);


    


}


void unite(int nb)//On inverse le nombre grace à un tableau
{

	int nb2=nb;
	int nb3 = 1;
	int compteur = 0;
	int mult = 1;
	int i;
	int reste;
	while(nb3 >= 1)
	{

		nb2 = nb2/10;
		nb3 = nb2*nb2;
		compteur ++;


	}

//printf("ici %d\n",compteur);

	for(i = 0;i<compteur-1;i++)
	{


		mult = mult*10;
	}
	reste = nb;
	int inter[compteur];
	
	

	for(i=0;i<compteur;i++)
	{

	        inter[i] = reste/mult;
		reste = reste %mult;

		//printf("indice  %d",inter[i]);
		mult = mult/10;

		
		

	}





	echange(inter,compteur);


}



void echangerbis(int nombre)//On échange le nombre sans tableau
{

        int nb2=nombre;
	int nb3 = 1;
	int compteur = 0;
	int mult = 1;
	int i;
	int reste;
	while(nb3 >= 1)
	{

		nb2 = nb2/10;
		nb3 = nb2*nb2;
		compteur ++;


	}

//printf("ici %d\n",compteur);

	for(i = 0;i<compteur-1;i++)
	{


		mult = mult*10;
	}
	reste = nombre;
	//int inter[compteur];
	
	int mult2 = 1;
	int resultat = 0;
	int inter;

	for(i=0;i<compteur;i++)
	{

	        inter = reste/mult;
		reste = reste %mult;
		
		resultat = resultat+(inter)*mult2;

                mult2 = mult2*10;
		//printf("indice  %d",i);
		mult = mult/10;

		
		

	}


printf("ici %d\n",resultat);







}




int main()
{
/*
	//On inverse un entier en passant par un tableau d'entiers
	printf("On inverse un entier en passant par un tableau d'entiers \n");
	unite(12000);
*/
/*
	//On inverse un entier sans passer par un tableau
	printf("On inverse un entier sans passer par un tableau d'entier \n");
	echangerbis(-1000023);

*/


}
