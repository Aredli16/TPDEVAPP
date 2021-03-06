//
// Created by corentin on 07/12/2021.
//

#include "films.h"

#include <string.h>

/**
 * Permet de créer un film
 * @param id Identifiant du film
 * @param titre Titre du film
 * @param realisateur Nom du réalisateur
 * @param acteurs Nom des acteurs
 * @param genre Genre du film
 * @param note Note du film
 * @param annee Année de sortie du film
 * @return Le film créé
 */
Film creer_films(int id, char *titre, char *realisateur, char *acteurs, char *genre, int note, int annee) {
	Film f;
	f.id = id;
	f.titre = titre;
	f.realisateur = realisateur;
	f.acteurs = acteurs;
	f.genre = genre;
	f.note = note;
	f.annee = annee;
	return f;
}

/**
 * Permet de saisir un film à partir de la console
 * @return Le film saisi
 */
Film saisir_film() {
	int id;
	char *titre = malloc(sizeof(char) * 100);
	char *realisateur = malloc(sizeof(char) * 100);
	char *acteurs = malloc(sizeof(char) * 100);
	char *genre = malloc(sizeof(char) * 100);
	int note;
	int annee;
	printf("Saisir l'id du film : ");
	scanf("%d", &id);
	printf("Saisir le titre du film : ");
	scanf("%s", titre);
	printf("Saisir le realisateur du film : ");
	scanf("%s", realisateur);
	printf("Saisir les acteurs du film : ");
	scanf("%s", acteurs);
	printf("Saisir le genre du film : ");
	scanf("%s", genre);
	printf("Saisir la note du film : ");
	scanf("%d", &note);
	printf("Saisir l'annee du film : ");
	scanf("%d", &annee);
	return creer_films(id, titre, realisateur, acteurs, genre, note, annee);
}

/**
 * Permet d'afficher un film
 * @param film Le film à afficher
 */
void afficher_film(Film film) {
	printf("Id : %d\n", film.id);
	printf("Titre : %s\n", film.titre);
	printf("Realisateur : %s\n", film.realisateur);
	printf("Acteurs : %s\n", film.acteurs);
	printf("Genre : %s\n", film.genre);
	printf("Note : %d\n", film.note);
	printf("Annee : %d\n", film.annee);
	printf("--------------------\n--------------------\n");
}

/**
 * Permet de libérer la mémoire d'un film
 * @param film Le film à libérer
 */
void liberer_film(Film film) {
	free(film.titre);
	free(film.realisateur);
	free(film.acteurs);
	free(film.genre);
}

/**
 * Permet de sauvegarder un film dans un fichier CSV
 * @param film Le film à sauvegarder
 */
void enregistrer_film(Film film, FILE *fichier) {
	fprintf(fichier, "%d;%s;%s;%s;%s;%d;%d\n", film.id, film.titre, film.realisateur, film.acteurs, film.genre,
	        film.note, film.annee);
}

/**
 * Permet de charger un film à partir d'un fichier CSV
 * @param fichier Le fichier CSV
 * @return Le film chargé
 */
Film charger_film(FILE *fichier) {
	int id;
	char *titre = malloc(sizeof(char) * 100);
	char *realisateur = malloc(sizeof(char) * 100);
	char *acteurs = malloc(sizeof(char) * 100);
	char *genre = malloc(sizeof(char) * 100);
	int note;
	int annee;
	fscanf(fichier, "%d;%[^;];%[^;];%[^;];%[^;];%d;%d\n", &id, titre, realisateur, acteurs, genre, &note, &annee);
	return creer_films(id, titre, realisateur, acteurs, genre, note, annee);
}