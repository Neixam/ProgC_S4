/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#ifndef __CHOMP__
#define __CHOMP__
#include "Position.h"
#include "Coup.h"
#include "Graphique.h"
#include "Joueur.h"
#include <ncurses.h>

/* Lance la partie numero 'num_partie' et l'affiche ainsi que le nombre de
*  partie 'nb_partie' renvoie le joueur gagnant de la partie et l'affiche */
Joueur partie(int num_partie, int nb_partie);

/* Recupere le nombre de partie voulant etre faites durant le match et lance
*  celui-ci. Affiche la gagnant de la serie si il y en a un */
void match(void);

#endif
