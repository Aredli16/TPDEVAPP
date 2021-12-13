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
	printf("4- Quitter\n");
}

/**
 * Fonction de traitement du choix de l'utilisateur
 * @param choix
 * @return 1 si le choix est valide, 0 sinon
 */
int traiter_choix_utilisateur(int choix, ArbreBinaire **arbre) {
	switch (choix) {
		case 1:
			inserer_film(&(*arbre), saisir_film());
			return 1;
		case 2:
			printf("Entrez l'identifiant du film recherché : ");
			scanf("%d", &choix);
			rechercher(*arbre, choix) ? printf("Film trouvé\n") : printf("Film non trouvé\n");
			return 1;
		case 3:
			afficher_arbre(*arbre);
			return 1;
		case 4:
			return 0;
		default:
			printf("Choix invalide\n");
			return 1;
	}
}