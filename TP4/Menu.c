/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 25-02-2020   */
#include "Menu.h"

Menu initialise_menu(void) {
    Menu ret;

    strcpy(ret.menu[0], "1 - Nouvelle partie");
    strcpy(ret.menu[1], "2 - Charger partie");
    strcpy(ret.menu[2], "3 - Option");
    strcpy(ret.menu[3], "4 - Credits");
    strcpy(ret.menu[4], "5 - Quitter");
    ret.selection = 0;
    return (ret);
}

void affiche_menu(Menu menu) {
    int i;

    assert(menu.selection < MENU);
    assert(menu.selection >= 0);
    attron(COLOR_PAIR(2));
    for (i = 0 ; i < MENU ; i++) {
        if (menu.selection == i) {
            attroff(COLOR_PAIR(2));
            attron(COLOR_PAIR(3));
        }
        mvprintw(LINES / 2 - 2 + i, COLS / 2, "%s", menu.menu[i]);
        if (menu.selection == i) {
            attroff(COLOR_PAIR(3));
            attron(COLOR_PAIR(2));
        }
    }
    attroff(COLOR_PAIR(2));
}

void menu(void) {
    Menu chomp_menu;
    int touche;

    chomp_menu = initialise_menu();
    while (1) {
        affiche_menu(chomp_menu)
        refresh();
        touche = getch();
        switch (touche) {
            case '1' : nouvelle_partie(); break;
            case '2' : charger_partie(); break;
            case '3' : option(); break;
            case '4' : credit(); break;
            case '5' : return ;
            case '\n' : switch (chomp_menu.selection) {
                            case 0 : nouvelle_partie(); break;
                            case 1 : charger_partie(); break;
                            case 2 : option(); break;
                            case 3 : credit(); break;
                            case 4 : return ;
                        }; break;
            case KEY_DOWN : (chomp_menu.selection == 4) ?
                            chomp_menu.selection = 0 : chomp_menu.selection++;
                            break;
            case KEY_UP : (chomp_menu.selection == 0) ?
                          chomp_menu.selection = 4 : chomp_menu.selection--;
                          break;
            default : break;
        }
        clear();
    }
}
