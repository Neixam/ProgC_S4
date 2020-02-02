#include <ncurses.h>

int		main(int ac, char **av)
{
	initscr();
	attron(A_UNDERLINE | A_BOLD);
	printw("*10*");
	refresh();
	getch();
	endwin();
	return (0);
}
