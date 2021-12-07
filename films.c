//
// Created by corentin on 07/12/2021.
//

#include "films.h"

Films *creer_films(int id, char *titre, char *realisateur, char *acteurs, char *genre, int note, int annee) {
	Films *f = malloc(sizeof(Films));
	f->id = id;
	f->titre = titre;
	f->realisateur = realisateur;
	f->acteurs = acteurs;
	f->genre = genre;
	f->note = note;
	f->annee = annee;
	return f;
}

Films *saisir_film() {
	int id;
	char titre[100];
	char realisateur[100];
	char acteurs[100];
	char genre[100];
	int note;
	int annee;
	printf("Saisir l'id du film : ");
	scanf("%d", &id);
	printf("Titre : ");
	scanf("%s", titre);
	printf("Realisateur : ");
	scanf("%s", realisateur);
	printf("Acteurs : ");
	scanf("%s", acteurs);
	printf("Genre : ");
	scanf("%s", genre);
	printf("Note : ");
	scanf("%d", &note);
	printf("Annee : ");
	scanf("%d", &annee);
	return creer_films(id, titre, realisateur, acteurs, genre, note, annee);
}

void afficher_film(Films *film) {
	printf("\nId : %d\n", film->id);
	printf("Titre : %s\n", film->titre);
	printf("Realisateur : %s\n", film->realisateur);
	printf("Acteurs : %s\n", film->acteurs);
	printf("Genre : %s\n", film->genre);
	printf("Note : %d\n", film->note);
	printf("Annee : %d\n", film->annee);
}