
//
// Created by corentin on 07/12/2021.
//

#include "arbre_binaire.h"

ArbreBinaire *inserer_film(ArbreBinaire *arbre, Films *film) {
	if (arbre == NULL) {
		arbre = malloc(sizeof(ArbreBinaire));
		if (arbre != NULL) {
			arbre->film = film;
			arbre->droite = NULL;
			arbre->gauche = NULL;
		}
	} else {
		if (arbre->film->id > film->id) {
			arbre->gauche = inserer_film(arbre->gauche, film);
		} else {
			arbre->droite = inserer_film(arbre->droite, film);
		}
	}
	return arbre;
}

int rechercher(ArbreBinaire *arbre, int id) {
	if (arbre == NULL) {
		return 0;
	} else {
		if (arbre->film->id == id) {
			return 1;
		} else if (arbre->film->id > id) {
			return rechercher(arbre->gauche, id);
		} else {
			return rechercher(arbre->droite, id);
		}
	}
}

void afficher_arbre(ArbreBinaire *arbre) {
	if (arbre != NULL) {
		afficher_arbre(arbre->gauche);
		afficher_film(arbre->film);
		afficher_arbre(arbre->droite);
	}
}