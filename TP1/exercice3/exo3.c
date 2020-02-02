#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int main() {
	int touche, val, delai;
	int	len;
	cbreak();
	len = strlen("Valeur : ");
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	val = 0;
	delai = 1000000;
	mvprintw(0, 0, "Valeur : %3d", val);
	while (1) {
		touche = getch();
		if (touche != ERR) {
			if (touche == 'r')
				val = 0;
			if (touche == KEY_UP)
				delai /= 2;
			if (touche == KEY_DOWN)
				delai *= 2;
			if (touche == 'q')
				break;
		}
		mvprintw(0, 0, "Valeur : ");
		attron(A_BOLD);
		mvprintw(0, len, "%3d", val);
		attroff(A_BOLD);
		refresh();
		val = (val + 1) % 128;
		usleep(delai);
	}
	getch();
	endwin();
	return 0;
}
