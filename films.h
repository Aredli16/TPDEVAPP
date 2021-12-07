//
// Created by corentin on 07/12/2021.
//

#ifndef TPDEVAPP_FILMS_H
#define TPDEVAPP_FILMS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _Films {
	int id;
	char *titre;
	char *realisateur;
	char *acteurs;
	char *genre;
	int note;
	int annee;
} Films;

Films *creer_films(int id, char *titre, char *realisateur, char *acteurs, char *genre, int note, int annee);
Films *saisir_film();
void afficher_film(Films *film);

#endif //TPDEVAPP_FILMS_H
