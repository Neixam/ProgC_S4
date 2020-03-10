/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 03-03-2020
*  Modification : 03-03-2020   */
#ifndef __SERPENT__
#define __SERPENT__

#include "Direction.h"
#include "Case.h"

typedef struct morceau {
    Direction sens;
    Case coord;
    struct morceau *corps;
} Morceau, *Serpent;

Case prochaine_case(Serpent serpent);
int ajout_morceau(Serpent *serpent, Case Nouvelle);

#endif
