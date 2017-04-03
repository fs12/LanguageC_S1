
#define TRUE 1
#define FALSE 0


typedef struct s_lettre{
	char lettre;
	int nb_occurences;
	}s_lettre;


typedef struct s_dico{
	int estFeuille;
	int estMot;
	int EstAnagramme;
	char lettre;
	struct s_dico* suivant[26];
	}s_dico;





int prochaine_case_libre(char* Tableau,int taille);
void afficher_tableau_caracatere(char* tab,int taille);

int taille_chaine(char* chaine)
{
	int i = 0;

	while (chaine[i] != '\0')
	{
		i++;
	}


	return i-1;


}


void afficher_tableau(int* tab,int taille)
{

	int i;
	
	for(i=0;i<taille;i++)
	{

		printf("%d \t",tab[i]);
	}



}

void afficher_structure_s_lettre(s_lettre structure)
{

		printf("lettre:%c\tnb_occurences:%d \n",structure.lettre,structure.nb_occurences);


}

void afficherTab_structure_s_lettre(s_lettre* structure,int taille)
{

	int i;
	for(i = 0;i<taille;i++)
	{
		afficher_structure_s_lettre(structure[i]);
	}

}

//fonction de debug 
void afficheTableauCompteurLettre(char* chaine ,s_lettre* tab)
{

	printf("\n%s\t-",chaine);
	int marqueur;

	int taille = taille_chaine(chaine);

	char tableau[taille];
	
	int i,z; 

	for(i=0;i<taille;i++)
	{
		tableau[i] = '1';
	}

	//afficher_tableau_caracatere(tableau,taille);

	for(i=0;i<taille;i++)
	{
		marqueur = 0;

		for(z=0;z<taille;z++)
		{
			if(tableau[z] == tab[i].lettre)
			 marqueur =1;

		}


		if(marqueur == 0)
		{
			
			
			tableau[prochaine_case_libre(tableau,taille)] = tab[i].lettre;

		}
		
	}


	int taille_finale = prochaine_case_libre(tableau,taille);
	//printf("%d",taille_finale);

	for(i=0;i<taille_finale-1;i++)
	{
		printf("%c : %d \t",tab[i].lettre,tab[i].nb_occurences);

	}
	printf("`\n");

}







void afficher_tableau_caracatere(char* tab,int taille)
{

	int i;
	
	for(i=0;i<taille;i++)
	{

		printf("%c \t",tab[i]);
	}



}



void anagramme(s_lettre* tab,int taille )
{

	int z,i,j;    //boucles for
	int max = 1;  //chiffres que je vais afficher 
	
	int mult = 1;
	char mot[35];

	
	int nb_lettre = 0;	            
	for(i = 0;i< taille ;i++)//On compte le nombre de lettre et on range nos lettres dans un tableau elles seront reconnues grace à un indice
	{
		int inter = tab[i].nb_occurences ;//nb d'occurences d'une seule lettre 
		while(inter != 0)    
		{
			mot[nb_lettre] = tab[i].lettre; //on remet toutes les lettres dans le tableau qui va nous servir a afficher 
			inter--;
			nb_lettre++; //nombre de lettres dans ce tableau
			
		}
		
	}


	//afficher_tableau_caracatere(mot,35);
	printf("nblettre : %d \n",nb_lettre);

	for(i=0;i<nb_lettre;i++)//cela va nous permettre de generer toutes les combinaisons dont on a besoin
	{

		max *=10;
	}
	
	
	int inter[nb_lettre]; //sert a stocker les bons numeros pour les afficher 

	
	for(i=0;i<max;i++)//On génère toutes les combinaisons
	{
		

		int marqueur = 0;
		mult = max/10;	
		int nombre = i;


		for(j=0;j<nb_lettre;j++)
		{
			
		  inter[j]=nombre/mult;    //On isole les milliers ,centaines ,unités etc..
		  nombre = nombre%mult;
		  mult = mult/10;
		  
		
			if(inter[j] >= nb_lettre)   //On met le marqueur à 1 si on a deja eu ce chiffre auparavant ou si le chiffre est trop grand par rapport aux indices qui nous interessent
			marqueur = 1; 

			for(z=0;z<j;z++)   //On vérifie si on a pas deja affiche cette lettre auparavant
			{
				if(inter[j] == inter[z])
					marqueur = 1;
			}

			

		}

		if (marqueur == 0)
		{
			for(j=0;j<nb_lettre;j++)
			{
				printf("%c",mot[inter[j]]);
			}
			printf("\n");

		}

		//printf("i = %d \n",i);
	}		
		
		
	

	




}





int appartient_Tableau(char* Tableau,char lettre)
{
	int i=0;
	
	while(i != '1')
	{
		if(lettre == Tableau[i])
			return i;

		i++;
		

	}


	return -1;





}


int prochaine_case_libre(char* Tableau,int taille)
{

	int i=0;
	
	while(Tableau[i] != '1' && i<taille)
	{
		
		//printf("on est la \n");
		i++;
		

	}


	return i;




}


//Cette fonction permet de transformer un mot en tableau de structures s_lettre
//Retourne un pointeur sur un tableau de structures s_lettre* alloué dynamiquement
s_lettre* creerTableauCompteurLettre(char* chaine)
{

	char tableau[26];
	int occurence[26];
	
	
	
	int i;

	for(i=0;i<26;i++)
	{
		tableau[i] = '1';
		occurence[i] = 0;
		
	}
	i=0;
	while (chaine[i] != '\0')
	{
		int test=appartient_Tableau(tableau,chaine[i]);
		//printf("test : %d\n",test);
		
		if( test==-1)

		{
			int case_libre = prochaine_case_libre(tableau,26);
			//printf("case_libre:%d\n",case_libre);
			tableau[case_libre] = chaine[i];
			occurence[case_libre]++;
			
		}

		else
		{

			occurence[test]++;
		}



               i++;
	}

	//afficher_tableau_caracatere(tableau,26);
	//printf("\n");
	//afficher_tableau(occurence,26);

	int taille = prochaine_case_libre(tableau,26);

	s_lettre* resultat = (s_lettre*)malloc((taille)*(sizeof(s_lettre)));


	for(i=0;i<taille;i++)
	{
		resultat[i].lettre = tableau[i];
		resultat[i].nb_occurences = occurence[i];

	}


	//afficherTab_structure_s_lettre(resultat,taille);

	return resultat;

	



}


s_dico* creerNoeud(char estFeuille , char estMot,char Lettre)//Crée un noeud et y insère une lettre
{

	s_dico* Noeud = (s_dico*)malloc(sizeof(s_dico));

	if(estFeuille == 'Y')
	Noeud->estFeuille = TRUE;
	else 
	Noeud->estFeuille = FALSE;
	


	if(estMot == 'Y')
	Noeud->estMot = TRUE;
	else
	Noeud->estMot = FALSE;


	Noeud->lettre = Lettre;

	return Noeud;
	




}



s_dico* creerNoeudDico(char estFeuille , char estMot)//Crée un noeud sans y insérer de lettre (Premier noeud de l'arbre)
{

	s_dico* Noeud = (s_dico*)malloc(sizeof(s_dico));

	if(estFeuille == 'Y')
	Noeud->estFeuille = TRUE;
	else 
	Noeud->estFeuille = FALSE;
	


	if(estMot == 'Y')
	Noeud->estMot = TRUE;
	else
	Noeud->estMot = FALSE;

	return Noeud;
	




}

s_dico* insererLettre(char lettre ,s_dico* dictionnaire,char estMot)
{
		int i,j;	


	for(i=0;i<26;i++)
	{
		if(dictionnaire->suivant[i] != NULL)
		{

			if(dictionnaire->suivant[i]->lettre == lettre)
			{
				if(estMot== 'Y')
				{
					dictionnaire->suivant[i]->estMot = 1;
					int marqueur = 0;
					//printf("a\n");

					for(j=0;j<26;j++)
					{
						if(dictionnaire->suivant[i]->suivant[j] != NULL)
						      marqueur = 1;


					}
				
					if (marqueur == 1)
					{
						dictionnaire->suivant[i]->estFeuille = 0;

					}
					else
					{

						dictionnaire->suivant[i]->estFeuille = 1;

					}
					



				}
				else
				{
					//printf("b\n");
					if(dictionnaire->suivant[i]->estMot != 1)				
					{

						dictionnaire->suivant[i]->estMot = 0;	
					}
				
					
				}
					break;



			}
		}
			
		

	
		else
		{
			
			dictionnaire->suivant[i] = creerNoeud('Y', estMot,lettre);
			break;
			 
		}
			
		
	
	}

	return dictionnaire->suivant[i];




}


void insererMot(char* mot,s_dico* dictionnaire)
{
	
	int i=0;
	while(mot[i] != '\n' && mot[i] != '\0' && mot[i] != ' ')
	{
		dictionnaire->estMot = 0;
		dictionnaire->estFeuille =0;
		
		if(mot[i+1] == '\n' || mot[i+1] == ' ' || mot[i+1] == '\0')
		{
			
			dictionnaire = insererLettre(mot[i],dictionnaire,'Y');


		}
		else 
		{
			
			dictionnaire = insererLettre(mot[i],dictionnaire,'Z');
		}

		//printf("mot[%d],%c\n",i,mot[i]);
		
		//printf("%d:%c estMot %d:estFeuille %d\n\n",i,dictionnaire->lettre,dictionnaire->estMot,dictionnaire->estFeuille);
		i++;



	}

	printf("\n");
	


}

void remplir_tableau(char* tab,char caractere,int taille)
{
	int i;

	for(i=0;i<taille;i++)
	tab[i] = caractere;

}


void lire(char* nom,s_dico* dictionnaire)//Cette fonction lit un fichier ligne par ligne et insère les mots dans le dictionnaire 
{
char chaine[40];
int j=0;

FILE* fichier = NULL;

fichier = fopen(nom,"r");
	
	
	
	if(fichier != NULL)
	{
				remplir_tableau(chaine,'\0',40);

		
    		
				while (fgets(chaine,1000,fichier) != NULL)
				{
					
						j++;
					//printf("avant %s\n",chaine);
					
					//printf("taille chaine:%d\n",strlen(chaine));
					//printf("la1%cla2",chaine[3]);
					insererMot(chaine,dictionnaire);
					
											

				}
				


			//printf("le fichier contient %d lignes  ",j);
	}

	else
	{
		printf("le fichier n'est pas ouvert\n");
	}


        fclose(fichier);  //On ferme le fichier ouvert 


}


char* trier_dictionnaire(char* transmis , int taille)//fonction de tri des lettres d'un mot
{

	int j,i;
	
	char temp;
	char* resultat;

	resultat = strdup(transmis);
        

        for (j= taille ;j>0;j--)
	{
		

		for(i=1 ; i<j; i++)
		{
			if (resultat[i] < resultat[i-1])
			{
				
				temp = resultat[i-1];
				
			       	resultat[i-1]=resultat[i];
				resultat[i] = temp;
			
			}
			
			
		
		} 

	}

			


	


	return resultat;
}



//Fonction d'affichage récursive du dictionnaire traite une seule lettre à la fois
//appelle trier_dictionnaire
//transmet le debut du mot à la fonction suivante 
//affiche si c'est un mot / s'arrete la si c'est une feuille 

void afficherDictionnaireBis(s_dico* dictionnaire,char* transmis,int val)
{                                                                        
	int i;                                                            
	
	int taille = 0;
	char* mot;
	char* atransmettre=(char*)malloc((val)*(sizeof(char)));
	
	
	for(i=0;i<val;i++) //On récupère le début du mot
	{
		atransmettre[i] = transmis[i];
		
	}
	

	atransmettre[val] = dictionnaire->lettre ;//On ajoute la lettre qui caractérise cet appel à notre mot 
	atransmettre[val+1]='\0';
	

	if(dictionnaire->estMot)//On affiche le mot s'il s'agit bien d'un mot
	{
		//printf("icibis");
		//printf("%d",val);
		printf("le mot est:%s\n",atransmettre);
		if(dictionnaire->estFeuille)
		return ;
	
	}
	




	
	for(i=0;i<26;i++)
	{
		if (dictionnaire->suivant[i] != NULL)//On récupère le nombre de lettres suivant cette lettre
		{
		
		
		taille++;
			 
	 	
		}
	
	}

	mot =(char*)malloc(taille*sizeof(char));
	
	for(i=0;i<taille;i++)//On crée un mot qui va nous servir à trier nos lettres dans l'ordre alphabétique pour pouvoir afficher dans l'ordre alphabétique
	{
		
		mot[i] = dictionnaire->suivant[i]->lettre;
	}


	mot = trier_dictionnaire(mot , taille);

	for(i=0;i<taille;i++)//Ces deux boucles permettent de traiter chaque mot dans l'ordre alphabétique
	{
		int j=0;
		
		while ( dictionnaire->suivant[j]->lettre != mot[i])
			{
				
				j++;	
			}

		afficherDictionnaireBis(dictionnaire->suivant[j],atransmettre,val+1);//On passe à la lettre suivante
	}








}



//Fonction d'affichage principale du dictionnaire dans l'ordre alphabétique traite une seule lettre à la fois 
//appelle trier_dictionnaire et afficherDictionnaireBis(s_dico* dictionnaire)
//transmet le debut du mot à la fonction suivante 

void afficherDictionnaire(s_dico* dictionnaire)
{

	int taille = 0,i;
	char* mot;
	
	
	for(i=0;i<26;i++)
	{
		if (dictionnaire->suivant[i] != NULL)//On récupère le nombre de lettres suivant cette lettre
		{
		
	
		taille++;
			 
	 	
		}
	
	}

	mot =(char*)malloc(taille*sizeof(char));
	
	for(i=0;i<taille;i++)//On crée un mot qui va nous servir à trier nos lettres dans l'ordre alphabétique pour pouvoir afficher dans l'ordre alphabétique
	{
		
		mot[i] = dictionnaire->suivant[i]->lettre;
	}


	mot = trier_dictionnaire(mot , taille);//On trie ce mot

	for(i=0;i<taille;i++)//Ces deux boucles permettent de traiter chaque mot dans l'ordre alphabétique
	{
		int j=0;
		
		while ( dictionnaire->suivant[j]->lettre != mot[i])
			{
				
				j++;	
			}

		afficherDictionnaireBis(dictionnaire->suivant[j],"",0);//On passe à la lettre suivante
	}

	

}

//Vérifie si mot appartient au dictionnaire  
int appartient_dictionnaire(char* mot,s_dico* dictionnaire)
{

	int taille = strlen(mot);
	int marqueur,i,compteur = 0;
	s_dico* intermediaire = dictionnaire;
	



	while(compteur < taille)
	{
		marqueur = 0;
		
		
		for(i=0 ; i < 26 ; i++)
		{
			if(intermediaire->suivant[i] != NULL)
			{
				//printf("%c\n",intermediaire->suivant[i]->lettre );
			
				if (intermediaire->suivant[i]->lettre  == mot[compteur])
					{
					
				      	      	marqueur = 1;
						/*printf("%c\n",intermediaire->suivant[i]->lettre );
					        printf("%d\n",intermediaire->suivant[i]->estMot );*/
					
				   		intermediaire = intermediaire->suivant[i];

                                          
				    		break;
				      
					}
			}

		}
		//printf("%c",intermediaire->lettre);
		//printf("Estmot %d \n",intermediaire->estMot);
		if (intermediaire->estMot == 1 && compteur==taille-1)
		{

			
			return  TRUE; 

		}


		if (marqueur == 0)
		{
			break;

		}
		
		
		


		compteur++;


	}



		return FALSE;



}



void marquer_mot(char* mot,s_dico* dictionnaire)
{

	int taille = strlen(mot);
	int i,compteur = 0;
	s_dico* intermediaire = dictionnaire;
	



	while(compteur < taille)
	{
		
		
		
		for(i=0 ; i < 26 ; i++)
		{
			if(intermediaire->suivant[i] != NULL)
			{
				//printf("%c\n",intermediaire->suivant[i]->lettre );
			
				if (intermediaire->suivant[i]->lettre  == mot[compteur])
					{
					
				      	      	
						/*printf("%c\n",intermediaire->suivant[i]->lettre );
					        printf("%d\n",intermediaire->suivant[i]->estMot );*/
					
				   		intermediaire = intermediaire->suivant[i];

                                          
				    		break;
				      
					}
			}

		}
		//printf("%c",intermediaire->lettre);
		//printf("Estmot %d \n",intermediaire->estMot);
		if (intermediaire->estMot == 1 && compteur==taille-1)
		{

			
			intermediaire->EstAnagramme = 1;

		}


		
		
		


		compteur++;


	}



		



}


//Retourne 1 si mot est préfixe d'un des mots du dictionnaire 0 sinon 
int estPrefixeDictionnaire(char* mot,s_dico* dictionnaire)
{
	int i = 0,j;
	int marqueur;

	while(i<strlen(mot))
	{
		marqueur = 0;
		for(j=0 ; j<26;j++)
		{
		
			if( dictionnaire->suivant[j] != NULL)
				{	
					if (mot[i] == dictionnaire->suivant[j]->lettre)
						{
							marqueur = 1;
							dictionnaire = dictionnaire->suivant[j];
							break;
						}
				}
		}
		
		if (marqueur == 0)
			return FALSE;

		if(i == strlen(mot) -1)

		{
                    
				
			for(j=0 ; j<26;j++)
			{

				if ( dictionnaire->suivant[j] != NULL)
					{
						return TRUE;
					}
			}
			return FALSE;

		}


			i++;

	}

	return FALSE;
		

}





//marque le champ est angramme de le derniere lettre du mot si le mot appartient au dictionnaitre et s'il a au moins un angramme dans le dictionnaire
void marquerCommeAnagrammeMot(char* mot,s_dico* dictionnaire)
{
     if(appartient_dictionnaire(mot,dictionnaire))
	{ 	
	
	//s_lettre* tab = creerTableauCompteurLettre(mot);
	//afficheTableauCompteurLettre(mot ,tab);
	char* anagramme;
	int z,j;    //boucles for
	long int max = 1;  //chiffres que je vais afficher 
	long int mult = 1;
	long int i;
	int nb_lettre = strlen(mot);	            
	char compare[nb_lettre];
	

	
	//printf("nblettre : %d \n",nb_lettre);

	for(i=0;i<nb_lettre;i++)//cela va nous permettre de generer toutes les combinaisons dont on a besoin
	{

		max *=10;
	}
	
	
	int inter[nb_lettre]; //sert a stocker les bons numeros pour les afficher 

	
	for(i=0;i<max;i++)//On génère toutes les combinaisons
	{
		
		//printf("traitement en cours....\n");
		int marqueur = 0;
		mult = max/10;	
		int nombre = i;

                
		for(j=0;j<nb_lettre;j++)
		{
			
		  inter[j]=nombre/mult;    //On isole les milliards,millions, milliers ,centaines ,unités etc..
		  nombre = nombre%mult;
		  mult = mult/10;
		  
		
			if(inter[j] >= nb_lettre)   //On met le marqueur à 1 si on a deja eu ce chiffre auparavant ou si le chiffre est trop grand par rapport aux indices qui nous interessent
			marqueur = 1; 
                        
			for(z=0;z<j;z++)   //On vérifie si on a pas deja affiche cette lettre auparavant
			{
				if(inter[j] == inter[z])
					marqueur = 1;
			}

		 

		}


		
		if (marqueur == 0)
		{
			
			anagramme = (char*)malloc(nb_lettre*sizeof(char));
			
			for(j=0;j<nb_lettre;j++)
			{
				//printf("%c",mot[inter[j]]);
				anagramme[j] = mot[inter[j]];
				
				
				
			}
			anagramme[nb_lettre]='\0';
			
			//printf("%s : %d\n",anagramme,strlen(anagramme));
			
			

			if(appartient_dictionnaire(anagramme,dictionnaire))
			{
				
				
				int compteur=0,c;
				s_dico* intermediaire = dictionnaire;
				//printf("nb_lettre:%d",nb_lettre);
				while(compteur<nb_lettre)
				{
					//printf("compteur:%d\n",compteur);
					for(c = 0 ; c < 26;c++)
					{
						
						if (intermediaire->suivant[c] != NULL)
						{
							if (intermediaire->suivant[c]->lettre == anagramme[compteur])
							{
								
								intermediaire = intermediaire->suivant[c];
								compare[compteur] = intermediaire->lettre;
								//printf("le resultat est : %c : %d\n",intermediaire->lettre,intermediaire->EstAnagramme);
								break;
								
							}

						}
					}
						

					if(compteur == nb_lettre-1)
					{
						compare[nb_lettre] ='\0';
						//printf("%s\n",compare);
						if(strcmp(compare,mot) != 0)
						{
					
						marquer_mot(mot,dictionnaire);
						printf("le mot %s est bien dans le dictionnaire et a au moins un anagramme dans le dictionnaire \nqui est le mot %s\n",mot,compare);
						printf("On met le champ EstAnagramme  de la dernière lettre de %s [%c] à %d\n",mot,intermediaire->lettre,intermediaire->EstAnagramme);
						return;
						}

					
						
					}
                                        compteur++;

				}
						
				
				
			}
	
			

			

		}


		
		//printf("i = %d \n",i);
	}
		printf("Ce mot n'admet pas d'anagramme dans le dictionnaire\n");		
	}
	else
	{
		printf("Ce mot n'appartient pas au dictionnaire. \n Il possède peut etre un anagramme mais il faut avant tout l'insérer dans le dictionnaire.\n");


	}	
		
	
//printf("%d",strlen(mot));


}


int estMarqueAnagrammeDictionnaire(char* mot,s_dico* dictionnaire)
{


	if(appartient_dictionnaire(mot,dictionnaire))
			{
				int compteur=0,c;
				
				//printf("nb_lettre:%d",nb_lettre);
				while(compteur<strlen(mot))
				{
					//printf("compteur:%d\n",compteur);
					for(c = 0 ; c < 26;c++)
					{
						
						if (dictionnaire->suivant[c] != NULL)
						{
							if (dictionnaire->suivant[c]->lettre == mot[compteur])
							{
								
								dictionnaire = dictionnaire->suivant[c];
								//printf("le resultat est : %c : %d\n",intermediaire->lettre,intermediaire->EstAnagramme);
								break;
								
							}

						}
					}
				
					if(compteur == strlen(mot)-1)
					{

						if (dictionnaire->EstAnagramme)
						printf("Est bien marque comme anagramme\n");
						return TRUE;
						
					}



	
					compteur++;
				}

				printf("Le mot n'a pas été marqué comme anagramme \n");
				return FALSE;


			}

	else
		printf("Le mot n'appartient donc pas au dictionnaire \n");


		return FALSE;
}



void afficherDictionnaireAnagrammeBis(s_dico* dictionnaire,char* transmis,int val)
{
	int i;
	
	int taille = 0;
	char* mot;
	char* atransmettre=(char*)malloc((val)*(sizeof(char)));
	
	
	for(i=0;i<val;i++)
	{
		atransmettre[i] = transmis[i];
		
	}
	

	atransmettre[val] = dictionnaire->lettre ;
	atransmettre[val+1]='\0';
	//printf("%s\n",atransmettre);

	if(dictionnaire->estMot)
	{	
		if(dictionnaire->EstAnagramme)
		//printf("icibis");
		{
			//printf("%d",val);
			printf("l'anagramme est:%s\n",atransmettre);
		}
		if(dictionnaire->estFeuille)
		return ;
	
	}
	




	
	for(i=0;i<26;i++)
	{
		if (dictionnaire->suivant[i] != NULL)
		{
		
		//printf("ici");
		taille++;
			 
	 	//afficherDictionnaireBis(dictionnaire->suivant[i],"",0);
		}
	
	}

	mot =(char*)malloc(taille*sizeof(char));
	
	for(i=0;i<taille;i++)
	{
		
		mot[i] = dictionnaire->suivant[i]->lettre;
	}


	mot = trier_dictionnaire(mot , taille);

	for(i=0;i<taille;i++)
	{
		int j=0;
		
		while ( dictionnaire->suivant[j]->lettre != mot[i])
			{
				
				j++;	
			}

		afficherDictionnaireAnagrammeBis(dictionnaire->suivant[j],atransmettre,val+1);
	}








}




void afficherDictionnaireAnagramme(s_dico* dictionnaire)
{
	printf("Affichage de tous les mots marques comme anagramme dans le dictionnaire\n");

	
	int taille = 0,i;
	char* mot;
	
	
		for(i=0;i<26;i++)
		{
			if (dictionnaire->suivant[i] != NULL)
			{
		
				
				taille++;
			 
	 			
			}
	
		}

	mot =(char*)malloc(taille*sizeof(char));

	

	
	
	for(i=0;i<taille;i++)
	{
		
		mot[i] = dictionnaire->suivant[i]->lettre;
	}


	mot = trier_dictionnaire(mot , taille);

	for(i=0;i<taille;i++)
	{
		int j=0;
		
		while ( dictionnaire->suivant[j]->lettre != mot[i])
			{
				
				j++;	
			}

		afficherDictionnaireAnagrammeBis(dictionnaire->suivant[j],"",0);
	}

}



void anagrammeDicoMarquer(char* chaine,s_dico* dictionnaire)
{




     if(appartient_dictionnaire(chaine,dictionnaire))
	{ 	
	
	//s_lettre* tab = creerTableauCompteurLettre(chaine);
	//afficheTableauCompteurLettre(chaine ,tab);
	char* anagramme;

	
	int z,i,j;    //boucles for
	int max = 1;  //chiffres que je vais afficher 
	
	int mult = 1;
	//char [35];

	
	int nb_lettre = strlen(chaine);	            
	

	
	//printf("nblettre : %d \n",nb_lettre);

	for(i=0;i<nb_lettre;i++)//cela va nous permettre de generer toutes les combinaisons dont on a besoin
	{

		max *=10;
	}
	
	
	int inter[nb_lettre]; //sert a stocker les bons numeros pour les afficher 

	
	for(i=0;i<max;i++)//On génère toutes les combinaisons
	{
		
		
		int marqueur = 0;
		mult = max/10;	
		int nombre = i;


		for(j=0;j<nb_lettre;j++)
		{
			
		  inter[j]=nombre/mult;    //On isole les milliers ,centaines ,unités etc..
		  nombre = nombre%mult;
		  mult = mult/10;
		  
		
			if(inter[j] >= nb_lettre)   //On met le marqueur à 1 si on a deja eu ce chiffre auparavant ou si le chiffre est trop grand par rapport aux indices qui nous interessent
			marqueur = 1; 

			for(z=0;z<j;z++)   //On vérifie si on a pas deja affiche cette lettre auparavant
			{
				if(inter[j] == inter[z])
					marqueur = 1;
				
			}

			

		}

		if (marqueur == 0)
		{
			

			anagramme = (char*)malloc(nb_lettre*sizeof(char));
			for(j=0;j<nb_lettre;j++)
			{
				//printf("%c",mot[inter[j]]);
				anagramme[j] = chaine[inter[j]];
				
				
			}
			//printf("%s\n",anagramme);
			anagramme[j]='\0';

			if(appartient_dictionnaire(anagramme,dictionnaire))
			{
				
				int compteur=0,c;
				s_dico* intermediaire = dictionnaire;
				//printf("nb_lettre:%d",nb_lettre);
				while(compteur<nb_lettre)
				{
					//printf("compteur:%d\n",compteur);
					for(c = 0 ; c < 26;c++)
					{
						
						if (intermediaire->suivant[c] != NULL)
						{
							if (intermediaire->suivant[c]->lettre == anagramme[compteur])
							{
								
								intermediaire = intermediaire->suivant[c];
								//printf("le resultat est : %c : %d\n",intermediaire->lettre,intermediaire->EstAnagramme);
								break;
								
							}

						}
					}

					if(compteur == nb_lettre-1)
					{
						if(strcmp(anagramme,chaine)!=0)
						{
							intermediaire->EstAnagramme = 1;
							//printf("le resultat est : %c : %d\n",intermediaire->lettre,intermediaire->EstAnagramme);
						}
					}
                                        compteur++;

				}	
				
				
			}
	
			

			

		}


		
		//printf("i = %d \n",i);
	}		
	}
	else
	{
		printf("Ce mot n'appartient pas au dictionnaire. \n Il possède peut etre un  ou des anagramme/s mais il faut avant tout l'insérer dans le dictionnaire.\n");


	}	
		
	
//printf("%d",strlen(mot));




}

//cette fonction permet de savoi si un mot appartient à un tableau de caracteres 
int appartient_tab_char(char** tab,int taille,char* mot)
{
	int i;
	for(i=0;i<taille;i++)
	{
		//printf("test:%s\n",tab[i]);
		if (strcmp(tab[i],mot)==0)
		return TRUE;
	}

	return FALSE;
}


//Meme fonction que anagrammeDicoMarquer() seulement ici on affiche au lieu de marquer le mot

void anagrammeDicoMarquerBis(char* chaine,s_dico* dictionnaire)
{




     if(appartient_dictionnaire(chaine,dictionnaire))
	{ 	
	
	//s_lettre* tab = creerTableauCompteurLettre(chaine);
	//afficheTableauCompteurLettre(chaine ,tab);
	char* anagramme;
	char* stock[10000];//On range la dedans chaque mot 
	int taille_stock=0;

	
	int z,i,j;    //boucles for
	int max = 1;  //chiffres que je vais afficher 
	
	int mult = 1;
	//char [35];

	
	int nb_lettre = strlen(chaine);	            
	

	
	//printf("nblettre : %d \n",nb_lettre);

	for(i=0;i<nb_lettre;i++)//cela va nous permettre de generer toutes les combinaisons dont on a besoin
	{

		max *=10;
	}
	
	
	int inter[nb_lettre]; //sert a stocker les bons numeros pour les afficher 

	
	for(i=0;i<max;i++)//On génère toutes les combinaisons
	{
		
		
		int marqueur = 0;
		mult = max/10;	
		int nombre = i;


		for(j=0;j<nb_lettre;j++)
		{
			
		  inter[j]=nombre/mult;    //On isole les milliers ,centaines ,unités etc..
		  nombre = nombre%mult;
		  mult = mult/10;
		  
		
			if(inter[j] >= nb_lettre)   //On met le marqueur à 1 si on a deja eu ce chiffre auparavant ou si le chiffre est trop grand par rapport aux indices qui nous interessent
			marqueur = 1; 

			for(z=0;z<j;z++)   //On vérifie si on a pas deja affiche cette lettre auparavant
			{
				if(inter[j] == inter[z])
					marqueur = 1;
				
			}

			

		}

		if (marqueur == 0)
		{
			

			anagramme = (char*)malloc(nb_lettre*sizeof(char));
			for(j=0;j<nb_lettre;j++)
			{
				//printf("%c",chaine[inter[j]]);
				anagramme[j] = chaine[inter[j]];
				
				

			}
			//printf("\n");
			//printf("%s\n",anagramme);
			anagramme[j]='\0';

			if(appartient_dictionnaire(anagramme,dictionnaire))
			{
				
				int compteur=0,c;
				s_dico* intermediaire = dictionnaire;
				//printf("nb_lettre:%d",nb_lettre);
				while(compteur<nb_lettre)
				{
					//printf("compteur:%d\n",compteur);
					for(c = 0 ; c < 26;c++)
					{
						
						if (intermediaire->suivant[c] != NULL)
						{
							if (intermediaire->suivant[c]->lettre == anagramme[compteur])
							{
								
								intermediaire = intermediaire->suivant[c];
								//printf("le resultat est : %c : %d\n",intermediaire->lettre,intermediaire->EstAnagramme);
								break;
								
							}

						}
					}

					if(compteur == nb_lettre-1)
					{
					
						
						if((strcmp(anagramme,chaine)!=0)&&(!appartient_tab_char(stock,taille_stock,anagramme)))
						{	
							
							stock[taille_stock]=strdup(anagramme);
							taille_stock++;
							//intermediaire->EstAnagramme = 1;
							printf("un anagramme de %s est : %s\n",chaine,anagramme);
							//printf("le resultat est : %c : %d\n",intermediaire->lettre,intermediaire->EstAnagramme);
						}
					}
					
                                        compteur++;

				}	
				
				
			}
	
			

			

		}


		
		//printf("i = %d \n",i);
	}	
		printf("\n");	
	}
	else
	{
		printf("Ce mot n'appartient pas au dictionnaire. \n Il possède peut etre un  ou des anagramme/s mais il faut avant tout l'insérer dans le dictionnaire.\n");


	}	
		
	
//printf("%d",strlen(mot));




}


void determineAnagrammeDictionnaire(char* nom,s_dico* dictionnaire)
{

	char chaine[1000];
int j=0;

FILE* fichier = NULL;




fichier = fopen(nom,"r");
	
	
	
	if(fichier != NULL)
	{

		
    		
		
		
		



			while (fgets(chaine,1000,fichier) != NULL)
				{
						j++;
					
					chaine[strlen(chaine)-1] = '\0';
					
					printf("-------------\nOn cherche les anagrammes de: %s \n\n",chaine);
					
					anagrammeDicoMarquerBis(chaine,dictionnaire);	
										


				}


			//printf("le fichier contient %d lignes  ",j);
	}

	else
	{
		printf("le fichier n'est pas ouvert\n");
	}


        fclose(fichier);  //On ferme le fichier ouvert 



}





