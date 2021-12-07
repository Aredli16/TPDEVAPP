//
// Created by corentin on 07/12/2021.
//

#ifndef TPDEVAPP_ARBRE_BINAIRE_H
#define TPDEVAPP_ARBRE_BINAIRE_H

#include <string.h>

#include "films.h"

typedef struct _ArbreBinaire {
	Films *film;
	struct _ArbreBinaire *gauche;
	struct _ArbreBinaire *droite;
} ArbreBinaire;

ArbreBinaire *inserer_film(ArbreBinaire *arbre, Films *film);

int rechercher(ArbreBinaire *arbre, int id);

void afficher_arbre(ArbreBinaire *arbre);

#endif //TPDEVAPP_ARBRE_BINAIRE_H
