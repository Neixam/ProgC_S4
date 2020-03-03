/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 25-02-2020   */
#ifndef __POSITION__
#define __POSITION__
#include "Joueur.h"
#include "Tablette.h"
#include <assert.h>
#include <string.h>

/* Represente le joueur qui joue le tour en cours ainsi que l'etat de la
*  tablette à ce moment */
typedef struct {
    Tablette tab;
    Joueur joueur;
} Position;

/* Verifie si la position 'pos' est en fin de partie et si oui affecte la valeur
*  du joueur gagnant a l'adresse 'joueur_gagnant' */
int est_jeu_termine(Position pos, Joueur *joueur_gagnant);

#endif
