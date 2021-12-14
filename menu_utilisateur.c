//
// Created by corentin on 13/12/2021.
//

#include "menu_utilisateur.h"

#include <stdio.h>

/**
 * Fonction d'affichage du menu utilisateur
 */
void afficher_menu_utilisateur() {
	printf("1- Ajouter un film\n");
	printf("2- Rechercher un film\n");
	printf("3- Afficher les films\n");
	printf("4- Supprimer un film\n");
	printf("5- Quitter\n");
}

void afficher_menu_recherche() {
	printf("1- Rechercher par id\n");
	printf("2- Rechercher par titre\n");
	printf("3- Retour\n");
}

/**
 * Fonction de traitement du choix de l'utilisateur
 * @param choix
 * @return 1 si le choix est valide, 0 sinon
 */
int traiter_choix_utilisateur(int choix, ArbreBinaire **arbre) {
	char titre_recherche[100];
	switch (choix) {
		case 1:
			inserer_film(&(*arbre), saisir_film());
			return 1;
		case 2:
			afficher_menu_recherche();
			printf("Votre recherche : ");
			scanf("%d", &choix);
			printf("\n");
			switch (choix) {
				case 1:
					printf("Entrez l'identifiant du film recherché : ");
					scanf("%d", &choix);
					printf("\n--------------------\n--------------------\n");
					rechercher_par_id(*arbre, choix) ? afficher_film(*rechercher_par_id(*arbre, choix)) : printf(
							"Film non trouvé\n");
					break;
				case 2:
					printf("Entrez le titre du film recherché : ");
					scanf("%s", titre_recherche);
					printf("\n--------------------\n--------------------\n");
					rechercher_film_par_titre(*arbre, titre_recherche) ? afficher_film(
							*rechercher_film_par_titre(*arbre, titre_recherche)) : printf("Film non trouvé\n");
					break;
				case 3:
					return 1;
				default:
					printf("Choix invalide\n");
					break;
			}
			return 1;
		case 3:
			printf("--------------------\n--------------------\n--------------------\n");
			afficher_arbre(*arbre);
			printf("--------------------\n");
			return 1;
		case 4:
			printf("Entre l'identifiant du film a supprimer : ");
			scanf("%d", &choix);
			supprimer_film_par_id(&(*arbre), choix);
			return 1;
		case 5:
			return 0;
		default:
			printf("Choix invalide\n");
			return 1;
	}
}