#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"anagramme.h" 




	

int main()
{
//PartieI
//Anagrammes
///*

	//crée le tableau de structures s_lettre
		s_lettre* tab = creerTableauCompteurLettre("anagramme");
	//affiche tous les anagrammes d'un mot donné
		anagramme(tab,5);
	//affiche un le contenu du tableau de structures s_lettre
	printf("\n\n----------On affiche le contenu de la structure s_lettre------\n");
		afficheTableauCompteurLettre("anagramme" ,tab);

//*/



//Partie II
//Dictionnaire	
	   	/*
		//Creer un noeud principal puis lire un fichier et insérer les mots dans le dictionnaire à partir du noeud principal
		//Toujours garder cette partie hors commentaire lorsque l'on utilise le dictionnaire
		s_dico* Noeud= creerNoeudDico('Z','Z');//On crée un noeud qui ne comporte pas de lettre
		lire("test.txt",Noeud);
		*/
		

		//s_dico* Noeud= creerNoeud('Z','Y','e');//créer un noeud qui comporte une lettre

		/*
		    //Insérer un mot dans le dictionnaire
		    insererMot("mot",Noeud);
		*/

		/*
		   //afficher le dictionnaire dans l'ordre alphabétique
		    afficherDictionnaire(Noeud);
		

		*/
		/*
		   //vérifier si un mot appartient bien au dictionnaire
		   if(appartient_dictionnaire("bleu",Noeud))
		   printf("Le mot appartient bien au dictionnaire \n");
		   else
		   printf("Le mot n'appartient pas au dictionnaire \n");
		
                */
		/*
		
			//verifier si un mot est préfixe d'un des mots du dictionnaire
			if(estPrefixeDictionnaire("boit",Noeud))
			printf("Ce mot est prefixe du dictionnaire \n");
			else
			printf("Ce mot n'est pas préfixe du dictionnaire \n");

		*/

		/*
		
			//Si ce mot a au moins un anagramme dans le dictionnaire cette fonction marque le champ EstAnagramme de la structure s_dico* à 1
			printf("----------------On teste la fonction : marquerCommeAnagrammeMot-----------------------------------\n");
			marquerCommeAnagrammeMot("crane",Noeud);


			printf("\n----------------On teste la fonction : afficherDictionnaireAnagramme-----------------------------------\n");
			afficherDictionnaireAnagramme(Noeud);





			printf("\n--------------- On teste la fonction ; estMarqueAnagrammeDictionnaire-----------------------------\n");
			//verifier si un mot est marque comme anagramme
			if(estMarqueAnagrammeDictionnaire("crane",Noeud))
			printf("Ce mot a été marqué comme anagramme dans le dictionnaire \n");
			else
			printf("Ce mot n'a donc pas été marqué comme anagramme dans le dictionnaire \n");


			printf("\n----------------On teste la fonction : afficherDictionnaireAnagramme-----------------------------------\n");
			afficherDictionnaireAnagramme(Noeud);

			//marquer comme anagramme tous les mots anagrammes du mot passé en parametre et presents dans le dictionnaire
			printf("\n--------------------On teste la fonction :anagrammeDicoMarquer-----------------\n");
			anagrammeDicoMarquer("crane",Noeud);


			printf("\n----------------On teste la fonction : afficherDictionnaireAnagramme-----------------------------------\n");
			afficherDictionnaireAnagramme(Noeud);

			


		*/

		/*    
			//Trouve tous les mots anagrammes des mots dans un fichier lu présents dans le dictionnaire 

			determineAnagrammeDictionnaire("annexe.txt",Noeud);

		*/





return 0;
}


