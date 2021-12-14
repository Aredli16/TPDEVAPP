//
// Created by corentin on 13/12/2021.
//

#ifndef TPDEVAPP_MENU_UTILISATEUR_H
#define TPDEVAPP_MENU_UTILISATEUR_H

#include "arbre_binaire.h"

/**
 * Fonction d'affichage du menu utilisateur
 */
void afficher_menu_utilisateur();

/**
 * Fonction de traitement du choix de l'utilisateur
 * @param choix
 * @return 1 si le choix est valide, 0 sinon
 */
int traiter_choix_utilisateur(int choix, ArbreBinaire **arbre);


#endif //TPDEVAPP_MENU_UTILISATEUR_H
