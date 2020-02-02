#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	int			touche;
	int			delay;
	int			x_o;
	int			y_o;
	int			x;
	int			y;
	int			nb_rd;

	srand(time(NULL));
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	delay = 1000000;
	curs_set(0);
	x_o = COLS / 2;
	y_o = LINES / 2;
	while (1)
	{
		mvaddch(y_o, x_o, 'o');
		touche = getch();
		if (touche != ERR)
		{
			if (touche == KEY_UP)
				delay *= 2;
			if (touche == KEY_DOWN)
				delay /= 2;
			if (touche == 'p')
			{
				do{
					touche = getch();
				}while (touche != 'p');
			}
			if (touche == '\n')
			{
				x_o = COLS / 2;
				y_o = LINES / 2;
				clear();
				refresh();
				continue;
			}
		}
		x = x_o;
		y = y_o;
		if ((nb_rd = rand() % 4) == 0 && x_o < COLS)
			x_o++;
		else if (nb_rd == 1 && x_o > 0)
			x_o--;
		else if (nb_rd == 2 && y_o < LINES)
			y_o++;
		else if (nb_rd == 3 && y_o > 0)
			y_o--;
		refresh();		
		usleep(delay);
		mvaddch(y, x, 'x');
	}
	endwin();
	return (0);
}
