#include <ncurses.h>

int		main(void)
{
	int		i;
	int		j;

	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	for (i = COLS / 2; i < COLS / 2 + 10; i++)
		for (j = LINES / 2 - 10 ; j < LINES / 2; j++)
		{
			if ((j + i) % 2 == 1)
				attron(COLOR_PAIR(1));
			else
				attron(COLOR_PAIR(2));
			mvaddch(j, i, '*');
			attroff(COLOR_PAIR(1) || COLOR_PAIR(2));
		}
	refresh();
	getch();
	endwin();
	return (0);
}
