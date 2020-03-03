/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#include "Chomp.h"
#include <ncurses.h>

int main(void) {
    initscr();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    match();
    getch();
    endwin();
    return (0);
}
