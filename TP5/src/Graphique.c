/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 08-03-2020
*  Modification : 08-03-2020   */
#include "Graphique.h"
#include <ncurses.h>
#include <assert.h>

void affiche_carre(int origine_y, int origine_x, int cote) {
    int i;
    int j;

    assert(origine_y + cote <= LINES);
    assert(origine_x + cote <= COLS);
    assert(origine_x >= 0);
    assert(origine_y >= 0);
    for (i = 0 ; i < cote ; i++) {
        for (j = 0 ; j < cote ; j++) {
            if (j == 0 || j == cote - 1)
                mvaddch(origine_y + i, origine_x + j,
                        (i == 0 || i == cote - 1) ? '+' : '|');
            else
                mvaddch(origine_y + i, origine_x + j,
                        (i == 0 || i == cote - 1) ? '-' : ' ');
        }
    }
}

void affiche_quadrillage(Monde mon) {
    int i;
    int j;

    for (i = 0 ; i < mon.nb_ligne ; i++) {
        for (j = 0 ; j < mon.nb_colonne ; j++)
            affiche_carre((COTE - 1) * i, (COTE - 1) * j, COTE);
    }
}

void affiche_pomme(Pomme pom) {
    int centre;

    centre = COTE / 2;
    attron(COLOR_PAIR(pom.effet + 1));
    mvaddch(pom.pos.coord_y * (COTE - 1) + centre,
            pom.pos.coord_x * (COTE - 1) + centre, 'o');
    attroff(COLOR_PAIR(pom.effet + 1));
}

void affiche_serpent(Serpent ser) {
    int centre;

    centre = COTE / 2;
    attron(COLOR_PAIR(TETE));
    mvaddch(ser->coord.coord_y * (COTE - 1) + centre,
            ser->coord.coord_x * (COTE - 1) + centre, 'o');
    ser = ser->corps;
    attroff(COLOR_PAIR(TETE));
    attron(COLOR_PAIR(MORCEAU));
    while (ser) {
        mvaddch(ser->coord.coord_y * (COTE - 1) + centre,
                ser->coord.coord_x * (COTE - 1) + centre, 'o');
        ser = ser->corps;
    }
    attroff(COLOR_PAIR(MORCEAU));
}

void affiche_monde(Monde mon) {
    EnsembleP tampon;

    affiche_quadrillage(mon);
    for (tampon = mon.pomme_presente ; tampon ; tampon = tampon->suivant)
        affiche_pomme(tampon->pomme);
    affiche_serpent(mon.serpent);
    mvprintw((COTE - 1) * mon.nb_ligne + 1, COLS / 2 - 10,
             "Le nombre de pomme mangee est : %2d", mon.nb_pomme_mangee);
}
