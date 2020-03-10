/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 09-03-2020
*  Modification : 09-03-2020   */
#include "Pomme.h"
#include "Menu.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    initscr();
    start_color();
    curs_set(0);
    init_pair(NORMAL + 1, COLOR_RED, COLOR_BLACK);
    init_pair(POISON + 1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(DOREE + 1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(ANXIOGENE + 1, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_GREEN, COLOR_BLACK);
    init_pair(UNSELECT, COLOR_WHITE, COLOR_BLACK);
    init_pair(SELECT, COLOR_BLACK, COLOR_WHITE);
    srand(time(NULL));
    menu();
    endwin();
    return (0);
}
