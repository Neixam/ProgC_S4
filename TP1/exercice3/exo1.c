#include <ncurses.h>

int main() {
	char chaine[128];
	int entier;
	int i;
	initscr();
	mvgetstr(2, 4, chaine);
	mvprintw(0, 0, "Chaine lue : %s", chaine);
	getch();
	clear();
	i = 0;
	while (1)
	{
		mvscanw(i, i, "%d", &entier);
		i++;
		if (entier == 0)
			break;
		refresh();
	}
	endwin();
	return 0;
}
