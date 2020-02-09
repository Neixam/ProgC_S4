/* Auteur       : A.Bourennane, T. Berthereau
*  Creation     : 04-02-2020
*  Modification : 09-02-2020                   */
#include <ncurses.h>

int main(void) {
    int i;
    int j;
    int centre_x;
    int centre_y;

    initscr();
    centre_y = LINES / 2 - 1;
    centre_x = COLS / 2 - 7;
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for (i = 0 ; i < 3 ; i++) {
        for (j = 0 ; j < 15 ; j++)
            mvaddch(centre_y + i, centre_x + j, '*');
    }
    refresh();
    getch();
    endwin();
    return (0);
}
