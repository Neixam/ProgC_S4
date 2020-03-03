/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 25-02-2020   */
#ifndef __MENU__
#define __MENU__
#define MENU 5
#define CONTENU 25
#include <string.h>
#include ""

typedef struct {
    char menu[MENU][CONTENU];
    int selection;
} Menu;

void menu(void);
Menu initialise_menu(void);

#endif
