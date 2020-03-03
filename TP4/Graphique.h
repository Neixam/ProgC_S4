/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 25-02-2020   */
#ifndef __GRAPHIQUE__
#define __GRAPHIQUE__
#include <ncurses.h>
#include <assert.h>
#include "Position.h"
#include "Coup.h"
#define COTE 2

/* Affiche sur la fenetre standard la position 'pos' */
void afficher_position(Position pos);

/* Recupere un clic souris de l'utilisateur et verifie si celui-ci est un coup
*  valide dans la position 'pos'  */
Coup lire_coup(Position pos);

#endif
