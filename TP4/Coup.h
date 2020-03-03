/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#ifndef __COUP__
#define __COUP__

#include "Joueur.h"
#include "Position.h"
#include "Tablette.h"
#include <assert.h>

/* Represente les coordonnees x et y d'un coup dans la tablette */
typedef struct {
    int coord_x;
    int coord_y;
} Coup;

/* Renvoie 1 si le coup 'coup' est valide dans la postion 'pos' et 0 sinon */
int est_legal(Position pos, Coup coup);

/* Joue le coup 'coup' dans la position 'pos' et passe au joueur suivant */
void jouer_coup(Position *pos, Coup coup);

#endif
