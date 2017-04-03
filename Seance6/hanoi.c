#include <stdlib.h>
#include <stdio.h>


int* remplir_tourprincipale(int N)
{

int* tab= (int*)malloc(N*(sizeof(int)));

int i;
	for(i=0;i<N;i++)
	{
		tab[i] = i+1 ;
	}


return tab;



}



int* remplir_tour(int N)
{

int* tab= (int*)malloc(N*(sizeof(int)));

int i;
	for(i=0;i<N;i++)
	{
		tab[i] =0;
	}


return tab;



}

void afficher_tour(int* tour,int N)
{

	int i,intermediaire;
        for(i=0;i<N;i++)
	{
		intermediaire = 0;
		while (intermediaire != tour[i])
		{printf(" _ ");
		//printf("tour2 : %d\n",tour2[i]);
		//printf("tour3 : %d \n",tour3[i]);
		intermediaire++;
		}
		printf("\n");
	}
	printf("\n");



}


void deplacer(int* origine , int* destination ,int N)
{

	int i,inter;
	i = 0;
	while (origine[i] == 0)
	{
		i++;

	}

	inter = origine[i];
	origine[i] =0;

	i = 0;
	while(destination[i] == 0 && i<N)
	{
		i++;
	}

           i--;

	destination[i] = inter;



	


	



}


void afficher_jeu(int* tour_depart,int* tour2,int* tour3,int N)
{

	/*int i,intermediaire;
        for(i=0;i<N;i++)
	{
		intermediaire = 0;
		while (intermediaire != tour_depart[i])
		{printf(" A ");
		//printf("tour2 : %d\n",tour2[i]);
		//printf("tour3 : %d \n",tour3[i]);
		intermediaire++;
		}
		printf("\n");
	}*/
	afficher_tour(tour_depart,N);
	afficher_tour(tour2,N);
	afficher_tour(tour3,N);
	





}

int continuer(int* tour,int N)
{
   int continuer = 1;
   int i;
   for ( i = 0 ;i<N;i++)
	{
		
		if (tour[i] != i+1)
		continuer = 0;

	}
	

	return continuer;
		



}




int trouver(int numero ,int* tab,int N)
{

	int i;
	for(i=0;i<N;i++)
	{
		if (tab[i] == numero)
		return i;
	}

	return -1;


}

int test (int* tour,int N)
{

int i = 0;
while(tour[i] == 0 && i<N)
 {

	i++;

 }

	return i-1;


}



void deplacer_numero(int* tour1,int* tour2,int* tour3,int N ,int indice)	
{
if (indice != 0)
  {if(tour1[indice-1]!= 0)
     	{
		printf("erreur , on reste au meme endroit\n");
		return;
	}
   }

int t2 = test(tour2,N);
int t3 = test(tour3,N);

printf("numero envoye sur t2 : %d",t2);
printf("numero envoye sur t3 : %d",t3);




if (t2 != -1)
	{
		if (t2 != N-1)
		{
			if (tour1[indice]<tour2[t2+1])
				{printf("on entre dans t2\n");
			 	deplacer(tour1,tour2,N);
				}
			else if (t3 != -1)
			 	{       if (t3 != N-1)
						{  printf("on entre dans t3bis\n");
						   //printf("gros%d",tour3[2]);
						 // printf("indice : %d  ,indicet3 :%d,tab %d ,tab2 %d\n",indice,t3,tour1[indice],tour3[t3+1]);
							//afficher_jeu(tour1,tour2,tour3,3);
							if (tour1[indice]<tour3[t3+1])
								{ printf("sortie t3bis\n");
			 					deplacer(tour1,tour3,N);
								}
							else  
			 					{
									printf("la petite sortie \n");
									return ;
					
								}
			

		
						}
					else 
					{	printf("la big sortie\n");
						deplacer(tour1,tour3,N);
					}
					
					
				}
			

		
		}

		else 
		{	printf("la sortie\n");
			deplacer(tour1,tour2,N);
		}
	}


else if (t3 != -1)
		{
			if (t3 != N-1)
						{  printf("on entre dans t3\n");
						   //printf("gros%d",tour3[2]);
						 // printf("indice : %d  ,indicet3 :%d,tab %d ,tab2 %d\n",indice,t3,tour1[indice],tour3[t3+1]);
							//afficher_jeu(tour1,tour2,tour3,3);
							if (tour1[indice]<tour3[t3+1])
								{ //printf("sortie t3bis\n");
			 					deplacer(tour1,tour3,N);
								}
							else  
			 					{
									printf("la petite sortie de t3\n");
									return ;
					
								}
			
						}
		}		






}
void bouger (int* tour_depart,int* tour2,int* tour3,int N,int numero)
{
	int t1 = trouver(numero,tour_depart,N);
	int t2 = trouver(numero,tour2,N);
	int t3 = trouver(numero,tour3,N);

	printf("numero trouve t1 : %d\n",t1);
	printf("numero trouve t2 : %d \n",t2);
	printf("numero trouve t3 : %d\n",t3);


	if (t1 != -1)
	{
		//printf("on est la \n");
		deplacer_numero(tour_depart,tour2,tour3,N ,t1);


	}

	if (t2 != -1)
	{

		deplacer_numero(tour2,tour3,tour_depart,N ,t2);
	}

	if (t3 != -1)
	{

		deplacer_numero(tour3,tour_depart,tour2,N ,t3);
	}





}



void hanoi(int* tour_depart,int* tour2,int* tour3,int N)
{

	int i ;
	int cont = 0;
	
	while ( cont == 0)

	{

		for (i = 1; i<= N;i++)
		{
			bouger(tour_depart,tour2,tour3,N,i);
			afficher_jeu(tour_depart,tour2,tour3,N);
			printf("___________________________________________________________________\n");
			cont = continuer(tour3,N);
			//printf("%d",cont);
			if(cont)
			break;
		}

               
		printf("boucle \n");
		

		

	




            

	}






}


int main()
{

int* tour_depart = remplir_tourprincipale(5);
int* tour2 = remplir_tour(5);
int* tour3 = remplir_tour(5);

afficher_jeu(tour_depart,tour2,tour3,5);
hanoi(tour_depart,tour2,tour3,5);




return 0;

}
