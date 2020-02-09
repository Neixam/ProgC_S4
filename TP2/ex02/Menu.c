/* Auteur       : A.Bourennane, T. Berthereau
*  Creation     : 09-02-2020
*  Modification : 09-02-2020                   */
#include <ncurses.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

/* Affiche un carré de côté 3 à partir de son sommet haut gauche aux coordonnées
*  (x, y) respectivement ('debut_abs', 'debut_ord')  */
void affiche_carre(int debut_ord, int debut_abs) {
    int i;
    int j;

    assert(debut_ord + 2 < LINES);
    assert(debut_abs + 3 < COLS);
    assert(debut_ord >= 0);
    assert(debut_abs >= 0);
    attron(COLOR_PAIR(3));
    for (i = 0 ; i < 3 ; i++) {
        for (j = 0 ; j < 3 ; j++)
            mvaddch(debut_ord + i, debut_abs + j, '\0');
    }
    attroff(COLOR_PAIR(3));
}

/* Affiche un rectangle blanc de la taille de la fenêtre */
void affiche_rectangle(void) {
    int i;
    int j;

    attron(COLOR_PAIR(4));
    for (i = 0 ; i < LINES ; i++) {
        for (j = 0 ; j < COLS ; j++)
            mvaddch(i, j, '\0');
    }
    attroff(COLOR_PAIR(4));
}

/* Affiche un carré bleu qui se déplace à une vitesse déterminé par 'delai'
*  dans un rectangle blanc */
void rebond(int delai) {
    int carre_ord;
    int carre_abs;
    int orientation_ord;
    int orientation_abs;
    int touche;

    assert(delai > 0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, FALSE);
    noecho();
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_WHITE, COLOR_WHITE);
    affiche_rectangle();
    carre_ord = LINES / 2 - 1;
    carre_abs = COLS / 2 - 1;
    affiche_carre(carre_ord, carre_abs);
    orientation_ord = 0;
    orientation_abs = 0;
    refresh();
    while (1) {
        touche = getch();
        if (touche == '\n') {
            while (1) {
                usleep(delai);
                affiche_rectangle();
                (orientation_ord == 0) ? carre_ord-- : carre_ord++;
                (orientation_abs == 0) ? carre_abs++ : carre_abs--;
                affiche_carre(carre_ord, carre_abs);
                refresh();
                if (carre_ord == 0)
                    orientation_ord = 1;
                if (carre_ord + 3 == LINES)
                    orientation_ord = 0;
                if (carre_abs == 0)
                    orientation_abs = 0;
                if (carre_abs + 4 == COLS)
                    orientation_abs = 1;
                touche = getch();
                if (touche == '\n') {
                    nodelay(stdscr, FALSE);
                    keypad(stdscr, TRUE);
                    echo();
                    return ;
                }
            }
        }
    }
}

/* Lis une valeur entière rentrer par l'utilisateur dans la fenêtre graphique
*  et l'affecte à 'delai' si celle-ci est strictement supérieur à 0           */
void option(int *delai) {
    int test;
    int ret;

    assert(delai != NULL);
    clear();
    curs_set(1);
    do {
        refresh();
        printw("la vitesse du petit carré est actuellement de %d micro-secondes",
              *delai);
        mvprintw(1, 0, "Inserer une nouvelle valeur : ");
        ret = mvscanw(1, 30, "%d", &test);
        clear();
    }while (test <= 0 && ret != ERR);
    *delai = test;
    curs_set(0);
}

/* Affiche dans la fenêtre graphique les crédits du programme                 */
void credit(void) {
    int y;
    int x;

    clear();
    y = LINES / 2;
    x = COLS / 2 - 20;
    mvprintw(y - 1, x, "Auteur : Amine Bourennane et Thomas Berthereau");
    mvprintw(y , x, "Binôme de tp de perfectionnement à la prog c");
    mvprintw(y + 1, x, "Dernière date de modification du programme : 09-01-2020");
    refresh();
    getch();
}

/* Affiche le contenue du menu dans la variable 'menu_cnt' à l'aide de sa
*  'taille' en surbrillant la selection de l'utilisateur déterminé par
*  'choix'                                                                    */
void affiche_menu(int choix, char menu_cnt[][25], int taille) {
    int i;

    assert(choix <= 3);
    assert(choix >= 0);
    assert(menu_cnt != NULL);
    attron(COLOR_PAIR(1));
    for (i = 0 ; i < taille ; i++) {
        if (choix == i) {
            attroff(COLOR_PAIR(1));
            attron(COLOR_PAIR(2));
        }
        mvprintw(LINES / 2 - 2 + i, COLS / 2, "%s", menu_cnt[i]);
        if (choix == i) {
            attroff(COLOR_PAIR(2));
            attron(COLOR_PAIR(1));
        }
    }
    attroff(COLOR_PAIR(1));
}


/* Sélectionne un comportement choisi par l'utilisateur à l'aide de 'choix' du
*  menu 'menu_cnt' et de taille 'taille' et sauvegarde la valeur de 'delai'   */
int menu(char menu_cnt[][25], int taille, int choix, int delai) {
    int touche;

    assert(menu_cnt != NULL);
    assert(taille > 0);
    assert(choix >= 0);
    assert(delai > 0);
    while (1) {
        affiche_menu(choix, menu_cnt, taille);
        refresh();
        touche = getch();
        switch (touche) {
            case '1' : rebond(delai); break;
            case '2' : option(&delai); break;
            case '3' : credit(); break;
            case '4' : return (1);
            case '\n' : switch (choix) {
                            case 0 : rebond(delai); break;
                            case 1 : option(&delai); break;
                            case 2 : credit(); break;
                            case 3 : return (1);
                        }; break;
            case KEY_DOWN : (choix == 3) ? choix = 0 : choix++; break;
            case KEY_UP : (choix == 0) ? choix = 3 : choix--; break;
            default : break;
        }
        clear();
    } 
}

int main(void) {
    char menu_cnt[4][25];

    initscr();
    strcpy(menu_cnt[0], "1 - Demarrer");
    strcpy(menu_cnt[1], "2 - Options");
    strcpy(menu_cnt[2], "3 - Credits");
    strcpy(menu_cnt[3], "4 - Quitter");
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    if (!menu(menu_cnt, 4, 0, 500000))
        exit(EXIT_FAILURE);
    endwin();
    return (0);
}
