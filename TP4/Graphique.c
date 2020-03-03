/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#include "Graphique.h"

/* Affiche un carre à partir des coordonnees 'coord_x' et 'coord_y' du sommet
*  en haut à droite de cote COTE */
void afficher_carre(int coord_y, int coord_x) {
    int i;
    int j;

    assert(coord_y + 1 < LINES);
    assert(coord_y >= 0);
    assert(coord_x + 1 < COLS);
    assert(coord_x >= 0);
    attron(COLOR_PAIR(1));
    for (i = 0 ; i < COTE ; i++)
        for (j = 0 ; j < COTE ; j++)
            mvaddch(coord_y + j, coord_x + i, '-');
    attroff(COLOR_PAIR(1));
}

/* Affiche sur la fenetre standard la position 'pos' */
void afficher_position(Position pos) {
    int i;
    int j;
    int coord_tab_x;
    int coord_tab_y;

    mvprintw(0, 0,"Tour du joueur %d", (pos.joueur == JOUEUR_1) ? 1 : 2);
    coord_tab_x = COLS / 2 - (M * COTE) / 2;
    coord_tab_y = LINES / 2 - (N * COTE) / 2;
    for (i = 0 ; i < N ; i++)
        for (j = 0 ; j < M ; j++)
            if (pos.tab.chocolat[i][j])
                afficher_carre(coord_tab_y + 3 * i, coord_tab_x + 3 * j);
}


/* Converti une coordonnee 'coord' x si 'choix' est a 0 et y sinon de la fenetre
*  standard en coordonnee du tableau tablette  */
int converti_x_y_tab(int coord, int choix) {
    int ret;
    int origine_tab_x;
    int origine_tab_y;

    if (choix) {
        origine_tab_y = LINES / 2 - (N * COTE) / 2;
        ret = ((coord - origine_tab_y) % 3 == 2) ? -1 : 
               (coord - origine_tab_y) / 3;
    }
    else {
        origine_tab_x = COLS / 2 - (M * COTE) / 2;
        ret = ((coord - origine_tab_x) % 3 == 2) ? -1 : 
               (coord - origine_tab_x) / 3;
    }
    return (ret);
}

/* Recupere un clic souris de l'utilisateur et verifie si celui-ci est un coup
*  valide dans la position 'pos'  */
Coup lire_coup(Position pos) {
    Coup retour;
    int touche;
    MEVENT ev;

    while (1) {
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            retour.coord_x = converti_x_y_tab(ev.x, 0);
            retour.coord_y = converti_x_y_tab(ev.y, 1);
            if (est_legal(pos, retour))
                return (retour);
        }
    }
}
