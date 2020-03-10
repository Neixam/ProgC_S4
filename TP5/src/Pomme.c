/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 09-03-2020
*  Modification : 09-03-2020   */
#include "Pomme.h"
#include <stdlib.h>
#include <time.h>

Pomme pomme_gen_alea(int n, int m) {
    int abscisse;
    int ordonnee;
    Pomme nouvelle;

    abscisse = rand() % n;
    ordonnee = rand() % m;
    nouvelle.pos.coord_x = abscisse;
    nouvelle.pos.coord_y = ordonnee;
    return nouvelle;
}

Pomme pomme_effet_gen_alea(int n, int m) {
    Pomme nouvelle;
    int alea;

    nouvelle = pomme_gen_alea(n, m);
    alea = rand() % 6;
    switch (alea) {
        case 0 :
        case 1 :
        case 2 : nouvelle.effet = NORMAL; break;
        case 3 : nouvelle.effet = ANXIOGENE; break;
        case 4 : nouvelle.effet = POISON; break;
        case 5 : nouvelle.effet = DOREE; break;
    }
    return nouvelle;
}
