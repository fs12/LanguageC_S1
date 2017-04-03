#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1;
#define FALSE 0;

typedef struct agenda{

	char* nom;
	char* prenom;
	int age;


}agenda;




void ecrire(char* nom,agenda* tab , int N)
{
	
	FILE* fichier = NULL;
	fichier = fopen(nom,"w+");
	int i;
	
	
	
	if(fichier != NULL)
	{
    
			for(i = 0;i < N ; i++)


			{
				

				
				fprintf(fichier,"%s\n",tab[i].nom);
				fprintf(fichier,"%s\n",tab[i].prenom);
				fprintf(fichier,"%d\n",tab[i].age);
				fprintf(fichier,"\n\n");
				

			}
				
				
			


		
		
			
		
		
	


	}

	else
	{
		printf("le fichier n'est pas ouvert\n");
	}


        fclose(fichier);  //On ferme le fichier ouvert 

}





agenda* nouveau(agenda* tab,int N,char* nom,char* prenom,int age)
{
	agenda* tableau = (agenda*)malloc((N+1)*(sizeof(agenda)));
	int i;
	
	for(i=0;i<N;i++)
	{
		tableau[i] = tab[i];
	}
	
	i = 0;
      	while( nom[i] != '\0')
	{
		i++;
		

	}
	tableau[N].nom = (char*)malloc(i*(sizeof(char)));
	
	strcpy(tableau[N].nom,nom);

	i = 0;
      	while( prenom[i] != '\0')
	{
		i++;
		

	}
	tableau[N].prenom = (char*)malloc(i*(sizeof(char)));
	strcpy(tableau[N].prenom,prenom);
	
	//while( nom[i] != '\0')
	//{
	//	tableau[N].nom[i] = nom[i];
	//	i++;

	//}
	//tableau[N].nom = nom ;
	//tableau[N].prenom = prenom;
	tableau[N].age = age;

	

	return tableau;

	



}

void afficher(agenda* tab,int N)
{
	
	int i;
	
	for(i=0;i<N;i++)
	{
		printf("nom: %s\t\t prenom:%s\t\t age:%d\t\t\n",tab[i].nom,tab[i].prenom,tab[i].age);	
	}


}


agenda* supprimer(char* nom , agenda* tab ,int N)
{
	

	int i=0,j;

	while (strcmp(tab[i].nom,nom))
	
	{

		i++;

	}
		//printf("%d",i);
	agenda tableau[N-1];

	for(j = 0;j<i;j++)
		{
			tableau[j].nom = tab[j].nom;
			
			tableau[j].prenom = tab[j].prenom;
			tableau[j].age = tab[j].age;
		}


	for(j = i;j<N-1;j++)
		{
			tableau[j].nom = tab[j+1].nom;
			
			tableau[j].prenom = tab[j+1].prenom;
			tableau[j].age = tab[j+1].age;
		}
	


	free(tab);
	tab=(agenda*)malloc((N-1)*(sizeof(agenda)));


	
	for(j = 0;j<N-1;j++)
		{
		        tab[j].nom = tableau[j].nom;
			
			tab[j].prenom = tableau[j].prenom;
			tab[j].age  = tableau[j].age;
		}



return tab;


	

	
	






}


void agemaxi(agenda* tab,int N,int age)
{

	int i;
		
	for(i = 0;i<N;i++)
		{
			if (tab[i].age > age)
			printf("maxi nom : %s \t prenom : %s \n",tab[i].nom,tab[i].prenom);

		}





}

void affichage(char* nom,agenda* tab,int N)
{


FILE* fichier = NULL;
	
	int caractere = 0;
	int i = 1,j=0;
	char chaine[1000];





fichier = fopen(nom,"r");
	
	char name[35];
	char nickname[35];
	int year;
	
	
	if(fichier != NULL)
	{

		
    			int i=1;
			int j = N,z = N;
		
		
		



			while (fgets(chaine,1000,fichier) != NULL)
				{       
					
				
					if (i%3 == 1)
					{printf("nom : %s\n",chaine);
					}
					
					if (i%3 == 2)
					{ printf("prenom :  %s\n",chaine);}
		
					if (i%3 == 0)
					{
						
						printf("age : %s\n",chaine);
						
					}
					

					i++;
				       
					


					
				}
			
			


			
	}

	else
	{
		printf("le fichier n'est pas ouvert\n");
	}


        fclose(fichier);  //On ferme le fichier ouvert 





}


agenda* lire(char* nom,agenda* tab,int N)
{


FILE* fichier = NULL;
	//fichier = fopen(nom,"r");
	int caractere = 0;
	int i = 1,j=0;
	char chaine[1000];

	



fichier = fopen(nom,"r");
	
	char* name;
	char* nickname;
	int year;
	
	
	if(fichier != NULL)
	{

		
    			int i=1;
			int j = N,z = N;
		
		
		



			while (fgets(chaine,1000,fichier) != NULL)
				{       
					
					
					if (i%3 == 1)
					{
					 name = strdup(chaine);
					 name[strlen(name)-1] = '\0';
					
					}
					
					if (i%3 == 2)
					{ nickname = strdup(chaine);
					  nickname[strlen(nickname)-1] = '\0';	}
		
					if (i%3 == 0)
					{
						
						year = atoi(chaine);
						tab = nouveau(tab,j,name,nickname,year);
						z = j;
						j++;				

					}
					

					i++;
				        
					


					
				}
			
			


			
	}

	else
	{
		printf("le fichier n'est pas ouvert\n");
	}


        fclose(fichier);  //On ferme le fichier ouvert 

	return tab;





}
int main()
{
	agenda* tableau = (agenda*)malloc(sizeof(agenda));
	//On ajoute une personne manuellement à l'agenda
	printf("\n-------On ajoute une personne manuellement a l'agenda\n");
	
	tableau[0].nom = "KILIT";
	tableau[0].prenom = "Elsa";
	tableau[0].age = 23;
	
	printf("\n------On ajoute une personne à l'agenda grace à la fonction nouveau--------\n");
	//On ajoute une personne grace à la fonction nouveau()
	tableau=nouveau(tableau,1,"SAKHI","Faical",23);

	printf("\n-----------On affiche alors ce qu'il y'a dans le fichier-----------\n"); 
	//On affiche ce qu'il y a dans le fichier
	affichage("agenda.txt",tableau ,2);

	//On copie dans l'agenda ce qu'il y'a dans le fichier
	printf("\n----On copie dans l'agenda ce qu'il y'a dans le fichier--------\n"); 

	
	tableau = lire("agenda.txt",tableau ,2);

	//Puis on affiche
	printf("\n---------On affiche a nouveau-------\n");
	afficher(tableau,5);
	
	printf("\n--------On ecrit dans le nouveau fichier notre agenda-------\n");
	//On ecrit dans le nouveau fichier notre agenda 
		ecrire("agenda_genere.txt",tableau ,5);

	printf("\n--------supprimer une personne---\n");
		tableau = supprimer("KILIT", tableau,5);
		afficher(tableau,4);
	
	printf("\n\n-----Les personnes qui ont plus de 21 sont:------\n");
	//Affiche toutes les personnes qui ont plus de 21 ans 
	agemaxi(tableau,2,21);
	
	
 


return 0;
}
