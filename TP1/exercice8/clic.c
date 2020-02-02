#include <ncurses.h>
#include <unistd.h>

int		main(void)
{
	int			touche;
	int			i;
	int			j;
	MEVENT		ev;

	initscr();
	char	s[LINES][COLS];
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	for (j = 0; j < LINES; j++)
		for (i = 0; i < COLS; i++)
		{
			s[j][i] = '0';
			addch(s[j][i]);
		}
	while (1)
	{
		touche = getch();
		if (touche == KEY_MOUSE && getmouse(&ev) == OK)
		{
			if (s[ev.y][ev.x] < '9')
			{
				s[ev.y][ev.x]++;
				mvaddch(ev.y, ev.x, s[ev.y][ev.x]);
			}
			else
			{
				init_pair(1, COLOR_BLUE, COLOR_BLUE);
				attron(COLOR_PAIR(1));
				mvaddch(ev.y, ev.x, ' ');
				attroff(COLOR_PAIR(1));
			}
		}
		refresh();
	}
	getch();
	endwin();
	return (0);
}
