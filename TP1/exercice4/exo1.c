#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define DELAY 500000

void dessiner_chat(int y, int x, int boo) {
	mvprintw(y, x, "*****");
	if (boo == 0)
		mvprintw(y + 1, x, "* * *");
	else
		mvprintw(y + 1, x, "*X*X*");
	mvprintw(y + 2, x, "*****");
}

void effacer_chat(int y, int x) {
	mvprintw(y, x, "     ");
	mvprintw(y + 1, x, "     ");
	mvprintw(y + 2, x, "     ");
}

int main() {
	int touche;
	int chat_x, chat_y;
	int souris_x, souris_y;

	MEVENT ev;
	srand(time(NULL));
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	mousemask(ALL_MOUSE_EVENTS
			| REPORT_MOUSE_POSITION, NULL);
	chat_x = rand() % (COLS - 4);
	chat_y = rand() % (LINES - 2);
	while (1) {
		touche = getch();
		if (touche == KEY_MOUSE
			&& getmouse(&ev) == OK) {
			souris_x = ev.x;
			souris_y = ev.y;
			if ((chat_x <= souris_x)
				&& (souris_x <= chat_x + 4)
				&& (chat_y <= souris_y)
				&& (souris_y <= chat_y + 2)) {
				if (souris_y == chat_y + 1 &&
					(souris_x == chat_x + 1 ||
					souris_x == chat_x + 3))
				{
					dessiner_chat(chat_y, chat_x, 1);
					refresh();
					usleep(DELAY);
				}
				effacer_chat(chat_y, chat_x);
				chat_x = rand() % (COLS - 4);
				chat_y = rand() % (LINES - 2);
				mvprintw(LINES / 2, COLS / 2, "Attrape !");
				refresh();
				usleep(DELAY);
				clear();
			}
		}
		dessiner_chat(chat_y, chat_x, 0);
		refresh();
	}
	getch();
	endwin();
	return 0;
}
