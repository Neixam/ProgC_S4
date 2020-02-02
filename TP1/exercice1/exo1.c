#include <ncurses.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	initscr();
	move(8, 4);
	addch('4');
	addch('!');
	addch('+');
	addch('2');
	addch('!');
	refresh();
	getch();
	mvaddch(8, 4, '4');
	mvaddch(8, 5, '!');
	mvaddch(8, 6, '+');
	mvaddch(8, 7, '2');
	mvaddch(8, 8, '!');
	refresh();
	getch();
	mvprintw(8, 4, "4!+2!");
	refresh();
	getch();
	endwin();
	return 0;
}
