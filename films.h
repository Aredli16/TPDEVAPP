//
// Created by corentin on 07/12/2021.
//

#ifndef TPDEVAPP_FILMS_H
#define TPDEVAPP_FILMS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Film {
	int id;
	char *titre;
	char *realisateur;
	char *acteurs;
	char *genre;
	int note;
	int annee;
} Film;

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
Film creer_films(int id, char *titre, char *realisateur, char *acteurs, char *genre, int note, int annee);

/**
 * Permet de saisir un film à partir de la console
 * @return Le film saisi
 */
Film saisir_film();

/**
 * Permet d'afficher un film
 * @param film Le film à afficher
 */
void afficher_film(Film film);

/**
 * Permet de libérer la mémoire d'un film
 * @param film Le film à libérer
 */
void liberer_film(Film film);

/**
 * Permet de sauvegarder un film dans un fichier CSV
 * @param film Le film à sauvegarder
 */
void enregistrer_film(Film film, FILE *fichier);

#endif //TPDEVAPP_FILMS_H
