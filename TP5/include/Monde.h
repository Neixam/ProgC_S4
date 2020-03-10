/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 03-03-2020
*  Modification : 03-03-2020   */
#ifndef __MONDE__
#define __MONDE__

#include "Pomme.h"
#include "Serpent.h"
#include <sys/time.h>
#define MORCEAU 5
#define TETE 6
#define DELAI 250000

typedef struct {
    int nb_ligne;
    int nb_colonne;
    Serpent serpent;
    EnsembleP pomme_presente;
    int boost_tour;
    int taille_serpent;
    struct timeval debut_boost;
    int nb_pomme_mangee;
} Monde;

int ajoute_pomme_monde(Monde *mon);
Serpent init_serpent(Monde mon);
int deplacer_serpent(Monde *mon);
int mort_serpent(Monde mon);
int intervalle_ms(struct timeval debut, struct timeval fin);
int manger_pomme_serpent(Monde *mon);
    
#endif
