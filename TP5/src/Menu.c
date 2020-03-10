/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 25-02-2020   */
#include "Menu.h"
#include "Monde.h"
#include "Serpent.h"
#include "Graphique.h"
#include "Case.h"
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <assert.h>

Monde init_monde(Option opt) {
    Monde retour;
    int i;

    retour.pomme_presente = NULL;
    retour.nb_ligne = opt.nb_ligne;
    retour.nb_colonne = opt.nb_colonne;
    retour.taille_serpent = opt.taille_serpent;
    retour.serpent = init_serpent(retour);
    retour.boost_tour = 0;
    retour.debut_boost.tv_sec = 0;
    retour.debut_boost.tv_usec = 0;
    for (i = 0 ; i < opt.nb_pommes ; i++) {
        while (!ajoute_pomme_monde(&retour));
    }
    retour.nb_pomme_mangee = 0;
	return (retour);
}

void jeu(Option opt) {
    Monde partie;
    int touche;
    int pomme_effet;
    int intervalle_boost;
    struct timeval fin;

    clear();
    noecho();
    partie = init_monde(opt);
    affiche_monde(partie);
    refresh();
    getch();
    cbreak();
    nodelay(stdscr, TRUE);
    pomme_effet = 0;
    while (1) {
        if (partie.boost_tour != 0) {
            gettimeofday(&fin, NULL);
            intervalle_boost = intervalle_ms(partie.debut_boost, fin);
            if (intervalle_boost > 5000) {
                partie.boost_tour = 0;
                partie.debut_boost.tv_sec = 0;
                partie.debut_boost.tv_usec = 0;
            }
        }
        if (mort_serpent(partie) || pomme_effet == -1) {
            clear();
            mvprintw(LINES / 2, COLS / 2 - 4, "PERDU !");
            refresh();
            cbreak();
            nodelay(stdscr, FALSE);
            getch();
            break;
        }
        if (!deplacer_serpent(&partie)) {
            if ((pomme_effet = manger_pomme_serpent(&partie)))
                while (!ajoute_pomme_monde(&partie));
        }
        affiche_monde(partie);
        refresh();
        touche = getch();
        switch (touche) {
            case 'q' : partie.serpent->sens = OUEST; break;
            case 'd' : partie.serpent->sens = EST; break;
            case 's' : partie.serpent->sens = SUD; break;
            case 'z' : partie.serpent->sens = NORD; break;
            case ' ' : while (getch() != ' '); break;
            default : break;
        }
        usleep(opt.duree_tour / ((!partie.boost_tour) ? 1 : partie.boost_tour * 2));
    }
}

void affiche_opt(Option opt, int selection) {
    int i;

    assert(selection < 6);
    assert(selection >= 0);
    attron(COLOR_PAIR(UNSELECT));
    for (i = 0 ; i < 6 ; i++) {
        if (selection == i) {
            attroff(COLOR_PAIR(UNSELECT));
            attron(COLOR_PAIR(SELECT));
        }
        switch (i) {
            case 0 : mvprintw(LINES / 2 - 2, COLS / 2, "Duree par tour (en ms) : %d",
                    opt.duree_tour); break;
            case 1 : mvprintw(LINES / 2 - 1, COLS / 2, "Taille du serpent : %d",
                    opt.taille_serpent); break;
            case 2 : mvprintw(LINES / 2, COLS / 2, "Largeur : %d",
                    opt.nb_colonne); break;
            case 3 : mvprintw(LINES / 2 + 1, COLS / 2, "Hauteur : %d",
                    opt.nb_ligne); break;
            case 4 : mvprintw(LINES / 2 + 2, COLS / 2, "Nombre de pommes : %d",
                    opt.nb_pommes); break;
            case 5 : mvprintw(LINES / 2 + 3, COLS / 2, "Confirmer"); break;
        }
        if (selection == i) {
            attroff(COLOR_PAIR(SELECT));
            attron(COLOR_PAIR(UNSELECT));
        }
    }
    attroff(COLOR_PAIR(UNSELECT));
}

void option(Option *opt) {
    int selection;
    int touche;

    selection = 0;
    echo();
    while (1) {
        affiche_opt(*opt, selection);
        refresh();
        touche = getch();
        switch (touche) {
            case '\n' : switch (selection) {
                            default : cbreak();
                            case 0 : mvscanw(LINES / 2 - 2, COLS / 2 + 25, "%d",
                                    &((*opt).duree_tour)); break;
                            case 1 : mvscanw(LINES / 2 - 1, COLS / 2 + 20, "%d",
                                    &((*opt).taille_serpent)); break;
                            case 2 : mvscanw(LINES / 2, COLS / 2 + 10, "%d",
                                    &((*opt).nb_colonne)); break;
                            case 3 : mvscanw(LINES / 2 + 1, COLS / 2 + 10, "%d",
                                    &((*opt).nb_ligne)); break;
                            case 4 : mvscanw(LINES / 2 + 2, COLS / 2 + 19, "%d",
                                    &((*opt).nb_pommes)); break;
                            case 5 : return ;
                        }; break;
            case 's' : (selection == 5) ? selection = 0 : selection++;
                            break;
            case 'z' : (selection == 0) ? selection = 5 : selection--;
                          break;
            default : break;
        }
        clear();
    }
}

Menu initialise_menu(void) {
    Menu ret;

    strcpy(ret.menu[0], "1 - Nouvelle partie");
    strcpy(ret.menu[1], "2 - Option");
    strcpy(ret.menu[2], "3 - Quitter");
    ret.selection = 0;
    return (ret);
}

Option initialise_option(void) {
    Option retour;

    retour.duree_tour = 154000;
    retour.taille_serpent = 3;
    retour.nb_colonne = 32;
    retour.nb_ligne = 16;
    retour.nb_pommes = 5;
    return (retour); 
}

void affiche_menu(Menu menu) {
    int i;

    assert(menu.selection < MENU);
    assert(menu.selection >= 0);
    attron(COLOR_PAIR(UNSELECT));
    for (i = 0 ; i < MENU ; i++) {
        if (menu.selection == i) {
            attroff(COLOR_PAIR(UNSELECT));
            attron(COLOR_PAIR(SELECT));
        }
        mvprintw(LINES / 2 - 2 + i, COLS / 2, "%s", menu.menu[i]);
        if (menu.selection == i) {
            attroff(COLOR_PAIR(SELECT));
            attron(COLOR_PAIR(UNSELECT));
        }
    }
    attroff(COLOR_PAIR(UNSELECT));
}

void menu(void) {
    Menu serpent_menu;
    Option opt;
    int touche;

    serpent_menu = initialise_menu();
    opt = initialise_option();
    while (1) {
        affiche_menu(serpent_menu);
        refresh();
        touche = getch();
        switch (touche) {
            case '1' : jeu(opt); break;
            case '2' : option(&opt); ;break;
            case '3' : return ;
            case '\n' : switch (serpent_menu.selection) {
                            case 0 : jeu(opt); break;
                            case 1 : option(&opt); break;
                            case 2 : return ;
                        }; break;
            case 's' : (serpent_menu.selection == 2) ?
                            serpent_menu.selection = 0 : serpent_menu.selection++;
                            break;
            case 'z' : (serpent_menu.selection == 0) ?
                          serpent_menu.selection = 2 : serpent_menu.selection--;
                          break;
            default : break;
        }
        clear();
    }
}
