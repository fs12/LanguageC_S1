#include<stdlib.h>
#include<stdio.h>


float Suite_1divisen_(int n)  // Suite   Resultat = 1/1+1/2+1/3+....+1/n
{
	float resultat=0;
	float inter;
	int i;

	for(i=1;i<= n;i++)
	{
        	inter = (float)1/i;  // toujours séparer les calculs castés
		resultat = resultat + inter;
	
	}

	printf("resultat: %f \n",resultat);
	return 	resultat;


}


int nb_de_chiffres(int n)   //Calculer le nombre de chiffres 
{
	int i=0;
	while(n >= 1)
	{
		n=n/10;
		i++;
	}
	
	//printf("%d\n",i);
	return i;
}


int extraitNombre(int nb,int numero_droite,int nb_chiffres)
{
	int i,j;
	int tableau[nb_chiffres];
	int inter=nb_de_chiffres(nb);
	int arret= inter-numero_droite+1;
	int arret2 =  arret-nb_chiffres;
	int mult=1;
	int resultat=0;
	for(i=1 ; i<inter ; i++)
	{
		
		mult = mult*10;
	}

	
	
	j=0;
	for(i=1;i<=arret;i++)
	{

		 if(i>=arret2 && i<=arret)
		  { 
			tableau[j]= nb/mult;
			j++;
		  }
		nb = nb%mult;
		mult = mult/10;
	}
	
	mult=1;

	for(i=1 ;i<nb_chiffres ;i++)
	{
		mult = mult*10;
	}

	for(i=0 ;i<nb_chiffres ;i++)
	{
		resultat = (tableau[i]*mult) + resultat;
		mult=mult/10;
	}

	printf("resultat = %d\n",resultat);

	return resultat;


	

	}



int sommeDesChiffres(int nb)//Somme des chiffres dans un nombre 
{
	int i,mult=1,resultat=0;
	int nb_chiffres = nb_de_chiffres(nb);
	
	for(i=1;i<nb_chiffres;i++)
	{
		mult = mult*10;
	}

	for(i=0;i<nb_chiffres;i++)
	{
		resultat = nb/mult + resultat;
		nb = nb%mult;
		mult /= 10;
	}

	//printf("resultat : %d\n",resultat);

	return resultat;


}


int nombre_couicable(int n)
{
	
	int i,j;
	int nb_chiffres = nb_de_chiffres(n);
	int mult=1;
	int tableau[nb_chiffres];

	for(i=1;i<nb_chiffres;i++)
	{
		mult = mult*10;
	}


	for(i=0;i<nb_chiffres;i++)
	{
		tableau[i] = n/mult;
		n = n%mult;
		mult = mult/10;
		
	}

	

	if(nb_chiffres%2 == 1)
	{
          int tableau1[nb_chiffres/2],tableau2[nb_chiffres/2];
	
          for(i=0;i<nb_chiffres/2;i++)
		{
			tableau1[i] = tableau[i];
			//printf("tableau1[%d] : %d",i,tableau1[i]);
		}
		j = 0;
	  
          for(i=(nb_chiffres/2)+1;i<nb_chiffres;i++)
		{
			
			tableau2[j] = tableau[i];
			//printf("tableau2[%d] : %d",j,tableau2[j]);
			j++;
		}


		int droite=0,gauche=0;
		int mult=1;
		for(i=1;i<(nb_chiffres/2);i++)
		{
			mult = mult*10;
		}

		for(i=0;i<(nb_chiffres/2);i++)
		{
			droite = droite + (tableau2[i]*mult);
			gauche = gauche + (tableau1[i]*mult);
			mult = mult/10;

		

		}

		//printf("droite : %d\n",droite);
	        //printf("gauche : %d\n",gauche);

		if (sommeDesChiffres(droite) == sommeDesChiffres(gauche))
		{  	printf("Couicable mais impair donc non couicable d'après l'énoncé!!!!\n");
			return 1;

		}
		else
		{
			printf("Non couicable  !!!\n");
			return 0;
		}

	
	   
	}
	else
	{


		int tableau1[nb_chiffres/2],tableau2[nb_chiffres/2];
	
          for(i=0;i<nb_chiffres/2;i++)
		{
			tableau1[i] = tableau[i];
			//printf("tableau1[%d] : %d",i,tableau1[i]);
		}
		j = 0;
	  
          for(i=(nb_chiffres/2);i<nb_chiffres;i++)
		{
			
			tableau2[j] = tableau[i];
			//printf("tableau2[%d] : %d",j,tableau2[j]);
			j++;
		}


		int droite=0,gauche=0;
		int mult=1;
		for(i=1;i<(nb_chiffres/2);i++)
		{
			mult = mult*10;
		}

		for(i=0;i<(nb_chiffres/2);i++)
		{
			droite = droite + (tableau2[i]*mult);
			gauche = gauche + (tableau1[i]*mult);
			mult = mult/10;

		

		}

		//printf("droite : %d\n",droite);
	        //printf("gauche : %d\n",gauche);

		if (sommeDesChiffres(droite) == sommeDesChiffres(gauche))
		{  	printf("Couicable!!!!\n");
			return 1;

		}
		else
		{
			printf("Non couicable !!!\n");
			return 0;
		}


	}



}

int main()
{
	/*
	//On veut calculer les n premiers termes de la suite 1+1/2+1/3+...1/n
		float a = Suite_1divisen_(2);
	*/
	/*
	//Calculer le nombre de chiffres dans un nombre
		printf("Ce nombre contient %d chiffres",nb_de_chiffres(12345)); 
	*/
	/*
	//extraire les chiffres entre une position et une autre dans le nombre 	on donne la taille et la position ici a partir du 4 eme nombre 3 chiffres  
		int c = extraitNombre(45863047,4,3);
	*/
	/*//On calcule la somme des chiffres dans un nombre 
		printf("La somme des chiffres dans ce nombre est égale à %d \n",sommeDesChiffres(12333));
	*/

	          
		//Permet de définir si un nombre est couicable ou non s'il l'est il est pair et la somme de sa partie gauche est égale à la somme de sa partie droite 
	        // J'ai modifié la fonction cette fonction peut définir si un nombre impair est couicable pour ce faire elle ne prend pas en compte le chiffre du milieu
		/*//cas impair
		nombre_couicable(362252263);
		*/
	

		///*//Cas pair
		nombre_couicable(36222263);
		//*/
		

	


}
