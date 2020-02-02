#include <ncurses.h>

int		main(void)
{
	int		i;
	int		j;
	int		nb;

	initscr();
	printw("longueur du triangle : ");
	mvscanw(0, 24, "%d", &nb);
	for (i = 0; i < nb; i++)
	{
		for (j = 0; j <= i; j++)
			mvaddch(i + 1, j, '*');
	}
	refresh();
	getch();
	endwin();
	return (0);
}
