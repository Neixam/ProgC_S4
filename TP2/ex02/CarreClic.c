/* Auteur       : A.Bourennane, T. Berthereau
*  Creation     : 04-02-2020
*  Modification : 09-02-2020                    */

#include <ncurses.h>

int main(void) {
    int i;
    int j;
    int centre_y;
    int centre_x;
    int touche;
    int couleur;

    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    couleur = 1;
    attron(COLOR_PAIR(couleur));
    centre_y = LINES / 2 - 3;
    centre_x = COLS / 2 - 3;
    for (i = 0 ; i < 7 ; i++) {
        for (j = 0 ; j < 7 ; j++)
            mvaddch(centre_y + i, centre_x + j, '*');
    }
    while (1) {
        touche = getch();
        if (touche == KEY_MOUSE) {
            attroff(COLOR_PAIR(couleur));
            if (couleur == 1)
                couleur++;
            else
                couleur = 1;
            attron(COLOR_PAIR(couleur));
            for (i = 0 ; i < 7 ; i++) {
                for (j = 0 ; j < 7 ; j++)
                    mvaddch(centre_y + i, centre_x + j, '*');
            }
        }
    }
    getch();
    endwin();
    return (0);
}
