#include<stdlib.h>
#include<stdio.h>

void viderBuffer(void)
{
	int c;
	while((c=getchar()) != EOF && c!= '\n');


}


int** allouer_matrice(int n)
{

	int** matrice = (int**)malloc(n*(sizeof(int*)));

	int i;
	
	for(i=0;i<n;i++)
	{

		matrice[i]=(int*)malloc(n*(sizeof(int)));

	}

	return matrice;



}


void detruire_matrice(int** matrice ,int n)
{
	int i;
	
	for(i=0 ; i<n ;i++)	
	{
		free(matrice[i]);

	}

	free(matrice);





}


int test_tableau(int** matrice,int n)
{
	int i;

	if(matrice == NULL)
	return -1;
	for(i = 0;i<n ;i++)
	{

		
			if(matrice[i] == NULL)
			return -1;

		

	}


	return 0;


}


void afficher_matrice(int** matrice ,int n)
{

	int i,j;
		
	for(i=0 ; i<n ;i++)
	{
		for(j=0 ; j<n ;j++)
		{

		printf("%d \t",matrice[i][j]);

		}
	printf("\n");



	}
	



}



int** mineur(int** matrice,int n,int indice_colonne)
{

	int** sortie=(int**)malloc((n-1)*(sizeof(int*)));
	int i,j,x=0,y=0;
	
	for(i=0;i<n-1;i++)
	{
	
		sortie[i] = (int*)malloc((n-1)*(sizeof(int)));


	}


	for(i=1 ;i<n;i++)
	{       y=0;
		for(j=0;j<n;j++)
		{
			if(j == indice_colonne)
			 { continue;}
			else
			{
				
				sortie[x][y] = matrice[i][j];
				//printf("mineur[%d][%d]:%d ,matrice[%d][%d]:%d\n ",x,y,sortie[x][y],i,j,matrice[i][j]);
				y++;
			}


		}

		x++;
	}

	return sortie;



}



int** saisirMatrice(int n)
{

	int** matrice = allouer_matrice(n);

	int i,j;
	
	
	for(i = 0;i<n ;i++)
	{

		for(j=0;j<n;j++)
		{
			printf("Entrez la valeur a la ligne %d et à la case %d\n",i,j);
			scanf("%d",&matrice[i][j]);
			viderBuffer();
			



		}



	}

	return matrice ;





}



int determinant (int** matrice,int n)
{ 
	

	if(n == 2)
	{
		return (matrice[0][0]*matrice[1][1])-(matrice[0][1]*matrice[1][0]);
	}


	else
	{
		int i;
		int** _mineur;
		int deter_mineur;
		int resultat = 0;
		int signe = 1;
		for(i=0 ; i<n ;i++)
		{
			printf("on fait le calcul grace aux mineurs suivants\n");
			_mineur = mineur(matrice,n,i);
			deter_mineur= determinant(_mineur,n-1);
			//printf("determinant:%d \n",deter_mineur);
			afficher_matrice(_mineur,2);
			//printf("matrice[1][%d] : %d , signe : %d ,resultat : %d\n",i,matrice[1][i],signe,resultat);
			resultat = resultat + (deter_mineur* matrice[0][i]*signe);
			signe *=-1;
			//printf("ICI_resultat:%d",resultat);
			


		}
		//printf("resultat:%d",resultat);

		return resultat;




	}


}


int main()
{
	//On crée notre matrice
		printf("\n-------Création d'une matrice------- \n");
	int** tab;
	/*
		//On peut aussi allouer de l'espace pour la matrice grace à la fonction suivante 
			tab=allouer_matrice(3);
	*/
	
	//On saisit au clavier notre matrice ici c'est une 3*3
		printf("\n--------Saisie au clavier de la matrice----------\n");
	tab=saisirMatrice(3);
		printf("\n------Affichage de la matrice----------\n");
	afficher_matrice(tab ,3);
	printf("\n");
		printf("\n--------Calcul du déterminant--------\n");
	int a =determinant (tab,3);
	printf("\nLe déterminant de la matrice est %d",a);
	printf("\n");

	/*
	
		//Calcul d'un mineur et affichage
		//tab=mineur(tab,3,2);
	
		//afficher_matrice(tab ,2);
	*/

	//On libère l'espace alloué à la matrice 
		detruire_matrice(tab,3);



		




return 0;
}
