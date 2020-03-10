/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 06-03-2020
*  Modification : 06-03-2020   */
#include "Serpent.h"
#include <stdlib.h>

Case prochaine_case(Serpent serpent) {
    Case retour;

    retour.coord_x = serpent->coord.coord_x;
    retour.coord_y = serpent->coord.coord_y;
	switch (serpent->sens) {
		case NORD : retour.coord_y--; break;
		case SUD : retour.coord_y++; break;
		case EST : retour.coord_x++; break;
		case OUEST : retour.coord_x--; break;
        default : break;
	}
    return (retour);
}

int ajout_morceau(Serpent *serpent, Case nouvelle) {
    Serpent tampon_s;

    tampon_s = *serpent;
    if (!(*serpent = (Serpent)malloc(sizeof(Morceau))))
        return (0);
    (*serpent)->sens = tampon_s->sens;
    (*serpent)->coord.coord_x = nouvelle.coord_x;
    (*serpent)->coord.coord_y = nouvelle.coord_y;
    (*serpent)->corps = tampon_s;
    return (1);
}
