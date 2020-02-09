/* Auteur       : Thomas Berthereau, Amine Bourenanne
*  Creation     : 09-02-2020
*  Modification : 09-02-2020                           */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ncurses.h>

/* Renvoie 0 si le caractère 'c' n'est pas affichable et 1 sinon */
int est_affichable(int c) {
    if (c <= '!' || c == 127)
        return (0);
    return (1);
}

/* Affiche un triangle avec une base de longueur 'base' et de hauteur 'hauteur'
*  avec le caractère 'c' */
void affiche_triangle(int base, int hauteur, int c) {
    int i;
    int j;

    assert(base > 0);
    assert(hauteur > 0);
    assert(est_affichable(c));
    for (i = 0 ; i < hauteur ; i++) {
        for (j = i ; j < base - i ; j++)
            mvaddch(i, j, c);
    }
}

int main(int ac, char **av) {
    int c;
    int n;

    if (ac != 3)
        exit(EXIT_FAILURE);
    if ((n = atoi(av[1])) < 0)
        exit(EXIT_FAILURE);
    c = av[2][0];
    if (est_affichable(c) == 0)
        exit(EXIT_FAILURE);
    initscr();
    curs_set(0);
    affiche_triangle(2 * n + 1, n + 1, c);
    refresh();
    getch();
    endwin();
    return (0);
}
