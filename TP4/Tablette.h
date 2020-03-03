/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#ifndef __TABLETTE__
#define __TABLETTE__
#define N 8
#define M 16
#include <assert.h>

/*Représente le plateau de jeu*/
typedef struct {
    int chocolat[N][M];
} Tablette;

/* Renvoie une tablette ou chacune de ses cases sont initialisees a 1 */
Tablette creer_tablette(void);

/* Affecte la valeur 0 a chacune des cases de la tablette 'tab' a partir de
*  la position 'x' et 'y' */
void manger(Tablette *tab, int x, int y);

#endif
