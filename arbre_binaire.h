//
// Created by corentin on 07/12/2021.
//

#ifndef TPDEVAPP_ARBRE_BINAIRE_H
#define TPDEVAPP_ARBRE_BINAIRE_H

#include <string.h>

#include "films.h"

typedef struct Noeud {
	Film film;
	struct Noeud *gauche;
	struct Noeud *droite;
} Noeud, ArbreBinaire;

/**
 * Permet d'insérer un film dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit inserer le film
 * @param film le film a inserer
 * @return le nouveau noeud de l'arbre
 */
void inserer_film(Noeud **noeud, Film film);

/**
 * Permet de rechercher un film dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit rechercher le film
 * @param id l'id du film a rechercher
 * @return Film le film rechercher, NULL sinon
 */
Film *rechercher_par_id(Noeud *noeud, int id);

/**
 * Permet de rechercher un film par son titre dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit rechercher le film
 * @param titre le titre du film a rechercher
 * @return Film le film trouve, NULL sinon
 */
Film *rechercher_film_par_titre(Noeud *noeud, char *titre);

/**
 * Permet d'afficher l'arbre binaire
 * @param noeud le noeud de l'arbre a afficher
 */
void afficher_arbre_croissant(Noeud *noeud);

/**
 * Permet d'afficher l'arbre binaire dans l'ordre décroissant des id
 * @param noeud le noeud de l'arbre a afficher
 */
void afficher_arbre_decroissant(Noeud *noeud);

/**
 * Permet de supprimer un film dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit supprimer le film
 * @param id l'id du film a supprimer
 */
void supprimer_film_par_id(Noeud **noeud, int id);

/**
 * Permet de liberer l'espace memoire alloue pour l'arbre binaire
 * @param noeud le noeud de l'arbre a liberer
 */
void liberer_arbre(Noeud *noeud);

/**
 * Permet d'enregistrer l'arbre binaire dans un fichier CSV
 * @param noeud Noeud a partir duquel on doit enregistrer l'arbre
 * @param fichier le fichier dans lequel on doit enregistrer l'arbre
 */
void enregistrer_arbre(Noeud *noeud, FILE *fichier);

/**
 * Permet de charger un arbre binaire depuis un fichier CSV
 * @param fichier le fichier depuis lequel on doit charger l'arbre
 * @return le noeud de l'arbre
 */
Noeud *charger_arbre(FILE *fichier);

#endif //TPDEVAPP_ARBRE_BINAIRE_H
