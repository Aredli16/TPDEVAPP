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
Noeud *inserer_film(Noeud *noeud, Film film);

/**
 * Permet de rechercher un film dans l'arbre binaire
 * @param noeud le noeud de l'arbre a partir duquel on doit rechercher le film
 * @param id l'id du film a rechercher
 * @return 1 si le film est trouve, 0 sinon
 */
int rechercher(Noeud *noeud, int id);

/**
 * Permet d'afficher l'arbre binaire
 * @param noeud le noeud de l'arbre a afficher
 */
void afficher_arbre(Noeud *noeud);

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

#endif //TPDEVAPP_ARBRE_BINAIRE_H
