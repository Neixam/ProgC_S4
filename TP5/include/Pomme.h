/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 03-03-2020
*  Modification : 03-03-2020   */
#ifndef __POMME__
#define __POMME__
#include "Case.h"

typedef enum {
    NORMAL,
    POISON,
    ANXIOGENE,
    DOREE
} Effets;

typedef struct {
    Case pos;
    Effets effet;
} Pomme;

typedef struct pommes {
    Pomme pomme;
    struct pommes *suivant;
} Pommes, *EnsembleP;

/* Renvoie une pomme sans effet de coordonnées (x, y) tel que
* 0 < x < n et 0 < y < m. */
Pomme pomme_gen_alea(int n, int m);

/* Renvoie une pomme de coordonnées (x, y) tel que
* 0 < x < n et 0 < y < m. La pomme reçoit un  des effets
* de façon aléatoire. */
Pomme pomme_effet_gen_alea(int n, int m);

#endif
