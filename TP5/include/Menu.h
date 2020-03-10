/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 25-02-2020   */
#ifndef __MENU__
#define __MENU__
#define MENU 3
#define CONTENU 25
#define SELECT 8
#define UNSELECT 7

typedef struct {
    char menu[MENU][CONTENU];
    int selection;
} Menu;

typedef struct {
    int duree_tour;
    int taille_serpent;
    int nb_colonne;
    int nb_ligne;
    int nb_pommes;
} Option;

void menu(void);
void jeu(Option opt);
Menu initialise_menu(void);

#endif
