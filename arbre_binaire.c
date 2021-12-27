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
	} else if (film.id == (*noeud)->film.id) {
		printf("Le film existe deja dans l'arbre\n");
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
 * @return Film le film rechercher, NULL sinon
 */
Film *rechercher_par_id(Noeud *noeud, int id) {
	if (noeud == NULL) {
		return 0;
	} else {
		if (noeud->film.id == id) {
			return &noeud->film;
		} else if (noeud->film.id > id) {
			return rechercher_par_id(noeud->gauche, id);
		} else {
			return rechercher_par_id(noeud->droite, id);
		}
	}
}

/**
 * Permet de rechercher un film par son titre dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit rechercher le film
 * @param titre le titre du film a rechercher
 * @return Film le film trouve, NULL sinon
 */
Film *rechercher_film_par_titre(Noeud *noeud, char *titre) {
	if (noeud == NULL) {
		return NULL;
	} else {
		if (strcmp(noeud->film.titre, titre) == 0) {
			return &noeud->film;
		} else {
			rechercher_film_par_titre(noeud->gauche, titre);
			rechercher_film_par_titre(noeud->droite, titre);
		}
	}

}

/**
 * Permet d'afficher l'arbre binaire
 * @param noeud le noeud de l'arbre a afficher
 */
void afficher_arbre_croissant(Noeud *noeud) {
	if (noeud != NULL) {
		afficher_arbre_croissant(noeud->gauche);
		afficher_film(noeud->film);
		afficher_arbre_croissant(noeud->droite);
	}
}

/**
 * Permet d'afficher l'arbre binaire dans l'ordre décroissant des id
 * @param noeud le noeud de l'arbre a afficher
 */
void afficher_arbre_decroissant(Noeud *noeud) {
	if (noeud != NULL) {
		afficher_arbre_decroissant(noeud->droite);
		afficher_film(noeud->film);
		afficher_arbre_decroissant(noeud->gauche);
	}
}

/**
 * Permet de supprimer un film dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit supprimer le film
 * @param id l'id du film a supprimer
 */
void supprimer_film_par_id(Noeud **noeud, int id) {
	if (*noeud != NULL) {
		if ((*noeud)->film.id == id) {
			if ((*noeud)->gauche == NULL && (*noeud)->droite == NULL) {
				liberer_film((*noeud)->film);
				free(*noeud);
				*noeud = NULL;
			} else if ((*noeud)->gauche == NULL) {
				liberer_film((*noeud)->film);
				Noeud *tmp = *noeud;
				*noeud = (*noeud)->droite;
				free(tmp);
			} else if ((*noeud)->droite == NULL) {
				liberer_film((*noeud)->film);
				Noeud *tmp = *noeud;
				*noeud = (*noeud)->gauche;
				free(tmp);
			} else {
				liberer_film((*noeud)->film);
				Noeud *tmp = *noeud;
				*noeud = (*noeud)->gauche;
				supprimer_film_par_id(&(*noeud)->droite, id);
				tmp->gauche = (*noeud)->gauche;
				tmp->droite = (*noeud)->droite;
				free(*noeud);
				*noeud = tmp;
			}
		} else if ((*noeud)->film.id > id) {
			supprimer_film_par_id(&(*noeud)->gauche, id);
		} else {
			supprimer_film_par_id(&(*noeud)->droite, id);
		}
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