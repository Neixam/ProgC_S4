#include <ncurses.h>

int main() {
	int touche;
	int x, y;
	int x_prec, y_prec;
	initscr();
	noecho();
	x = COLS / 2;
	y = LINES / 2;
	mvaddch(y, x, 'o');
	curs_set(0);
	while (1) {
		x_prec = x;
		y_prec = y;
		touche = getch();
		if (touche == 'i')
		{
			x = COLS / 2;
			y = LINES / 2;
		}
		if (touche == 'q' && x > 0)
			x -= 1;
		if (touche == 'd' && x < COLS - 1)
			x += 1;
		if (touche == 'z' && y > 0)
			y -= 1;
		if (touche == 's' && y < LINES - 1)
			y += 1;
		mvaddch(y_prec, x_prec, ' ');
		mvaddch(y, x, 'o');
		refresh();
	}
	getch();
	endwin();
	return 0;
}
