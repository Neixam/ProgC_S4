#include <ncurses.h>
#include <unistd.h>
#define DELAI 50000

int main() {

	int x, y;
	initscr();
	x = 0;
	y = 0;
	while(1) {
		clear();
		mvaddch(y, x, 'o');
		usleep(DELAI);
		refresh();
		x = (x + 1) % COLS;
		y = (y + 1) % LINES;
	}
	endwin();
	return 0;
}
