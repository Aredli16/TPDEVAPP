
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
Noeud *inserer_film(Noeud *noeud, Film film) {
	if (noeud == NULL) {
		noeud = malloc(sizeof(Noeud));
		if (noeud != NULL) {
			noeud->film = film;
			noeud->droite = NULL;
			noeud->gauche = NULL;
		}
	} else {
		if (noeud->film.id > film.id) {
			noeud->gauche = inserer_film(noeud->gauche, film);
		} else {
			noeud->droite = inserer_film(noeud->droite, film);
		}
	}
	return noeud;
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