/* Auteur       : A.Bourennane, T. Berthereau
*  Creation     : 04-02-2020
*  Modification : 09-02-2020                                                  */
#include <ncurses.h>
#include <unistd.h>
#include <assert.h>
#define DELAI 500000

/* Affiche un carré bleu de côté 3 à partir des coordonnées 'debut_ord'
*  et 'debut_abs' qui représente respectivement la coordonnée y et x du
*  sommet en haut à gauche du carré.                                          */
void affiche_carre(int debut_ord, int debut_abs) {
    int i;
    int j;

    assert(debut_ord + 2 < LINES);
    assert(debut_abs + 3 < COLS);
    assert(debut_ord >= 0);
    assert(debut_abs >= 0);
    attron(COLOR_PAIR(1));
    for (i = 0 ; i < 3 ; i++) {
        for (j = 0 ; j < 3 ; j++)
            mvaddch(debut_ord + i, debut_abs + j, '\0');
    }
    attroff(COLOR_PAIR(1));
}
/* Affiche un rectangle blanc de la taille de la fenêtre.                     */
void affiche_rectangle(void) {
    int i;
    int j;

    attron(COLOR_PAIR(2));
    for (i = 0 ; i < LINES ; i++) {
        for (j = 0 ; j < COLS ; j++)
            mvaddch(i, j, '\0');
    }
    attroff(COLOR_PAIR(2));
}

int main(void) {
    int carre_ord;
    int carre_abs;
    int orientation_ord;
    int orientation_abs;
    int touche;

    initscr();
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    affiche_rectangle();
    carre_ord = LINES / 2 - 1;
    carre_abs = COLS / 2 - 1;
    affiche_carre(carre_ord, carre_abs);
    orientation_ord = 0;
    orientation_abs = 0;
    while (1) {
        touche = getch();
        if (touche == '\n') {
            while (1) {
                usleep(DELAI);
                affiche_rectangle();
                if (orientation_ord == 0)
                    carre_ord--;
                else
                   carre_ord++;
                if (orientation_abs == 0)
                    carre_abs++;
                else
                   carre_abs--;
                affiche_carre(carre_ord, carre_abs);
                if (carre_ord == 0)
                    orientation_ord = 1;
                if (carre_ord + 3 == LINES)
                    orientation_ord = 0;
                if (carre_abs == 0)
                    orientation_abs = 0;
                if (carre_abs + 4 == COLS)
                    orientation_abs = 1;
                refresh();
                touche = getch();
                if (touche == '\n') {
                    endwin();
                    return (0);
                }
            }
        }
    }
    getch();
    endwin();
    return (0);
}
