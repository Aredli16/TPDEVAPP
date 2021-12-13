//
// Created by corentin on 07/12/2021.
//

#include "arbre_binaire.h"

/**
 * Permet d'insérer un film dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit inserer le film
 * @param film le film a inserer
 * @return le nouveau noeud de l'arbre
 */
void inserer_film(Noeud **noeud, Film film) {
	if (*noeud == NULL) {
		*noeud = malloc(sizeof(Noeud));
		if (*noeud != NULL) {
			(*noeud)->film = film;
			(*noeud)->droite = NULL;
			(*noeud)->gauche = NULL;
		}
	} else {
		if ((*noeud)->film.id > film.id) {
			inserer_film(&(*noeud)->gauche, film);
		} else {
			inserer_film(&(*noeud)->droite, film);
		}
	}
}

/**
 * Permet de rechercher un film dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit rechercher le film
 * @param id l'id du film a rechercher
 * @return 1 si le film est trouve, 0 sinon
 */
int rechercher(Noeud *noeud, int id) {
	if (noeud == NULL) {
		return 0;
	} else {
		if (noeud->film.id == id) {
			return 1;
		} else if (noeud->film.id > id) {
			return rechercher(noeud->gauche, id);
		} else {
			return rechercher(noeud->droite, id);
		}
	}
}

/**
 * Permet d'afficher l'arbre binaire
 * @param noeud le noeud de l'arbre a afficher
 */
void afficher_arbre(Noeud *noeud) {
	if (noeud != NULL) {
		afficher_arbre(noeud->gauche);
		afficher_film(noeud->film);
		afficher_arbre(noeud->droite);
	}
}

/**
 * Permet de liberer l'espace memoire alloue pour l'arbre binaire
 * @param noeud le noeud de l'arbre a liberer
 */
void liberer_arbre(Noeud *noeud) {
	if (noeud != NULL) {
		liberer_arbre(noeud->gauche);
		liberer_arbre(noeud->droite);
		liberer_film(noeud->film);
		free(noeud);
	}
}

/**
 * Permet d'enregistrer l'arbre binaire dans un fichier CSV
 * @param noeud Noeud a partir duquel on doit enregistrer l'arbre
 * @param fichier le fichier dans lequel on doit enregistrer l'arbre
 */
void enregistrer_arbre(Noeud *noeud, FILE *fichier) {
	if (noeud != NULL) {
		enregistrer_arbre(noeud->gauche, fichier);
		enregistrer_film(noeud->film, fichier);
		enregistrer_arbre(noeud->droite, fichier);
	}
}

/**
 * Permet de charger un arbre binaire depuis un fichier CSV
 * @param fichier le fichier depuis lequel on doit charger l'arbre
 * @return le noeud de l'arbre
 */
Noeud *charger_arbre(FILE *fichier) {
	Noeud *noeud = NULL;
	Film film;
	if (fichier != NULL) {
		while (!feof(fichier)) {
			film = charger_film(fichier);
			inserer_film(&noeud, film);
		}
	}
	return noeud;
}