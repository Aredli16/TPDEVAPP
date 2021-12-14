#if defined WIN32 || defined (WIN64)

#include <windows.h>

#else

#include <unistd.h>

#endif

#include <stdio.h>

#include "menu_utilisateur.h"

void temporiser(int temps) {
#if defined WIN32 || defined (WIN64)
	Sleep(temps * 1000);
#else
	sleep(temps);
#endif
}

void charger_films_dans_arbre(FILE **fichier, ArbreBinaire **arbre) {
	temporiser(1);
	printf("Chargement des films...\n");
	*fichier = fopen("arbre.csv", "r");
	if (*fichier != NULL) {
		*arbre = charger_arbre(*fichier);
		fclose(*fichier);
	}
	temporiser(1);
}

void sauvegarder_films_arbre(FILE **fichier, ArbreBinaire **arbre) {
	printf("Sauvegarde des films...\n");
	*fichier = fopen("arbre.csv", "w");
	if (*fichier != NULL) {
		enregistrer_arbre(*arbre, *fichier);
		fclose(*fichier);
	}
	temporiser(1);
}

void liberer_arbre_film(ArbreBinaire **arbre) {
	printf("Liberation de la memoire...\n");
	liberer_arbre(*arbre);
	*arbre = NULL;
	temporiser(1);
}

int main() {
	ArbreBinaire *arbre = NULL;
	FILE *fichier = NULL;
	int choix;

	charger_films_dans_arbre(&fichier, &arbre);

	do {
		printf("\n");
		afficher_menu_utilisateur();
		printf("Votre choix : ");
		scanf("%d", &choix);
		printf("\n");
	} while (traiter_choix_utilisateur(choix, &arbre));

	sauvegarder_films_arbre(&fichier, &arbre);
	liberer_arbre_film(&arbre);

	return 0;
}
