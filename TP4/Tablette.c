/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#include "Tablette.h"

/* Renvoie une tablette ou chacune de ses cases sont initialisees a 1 */
Tablette creer_tablette(void) {
    int i;
    int j;
    Tablette tab;

    for (i = 0 ; i < N ; i++)
        for (j = 0 ; j < M ; j++)
            tab.chocolat[i][j] = 1;
    return (tab);
}

/* Affecte la valeur 0 a chacune des cases de la tablette 'tab' a partir de
*  la position 'x' et 'y' */
void manger(Tablette *tab, int x, int y) {
    int i;
    int j;

    assert(x < M);
    assert(x >= 0);
    assert(y < N);
    assert(y >= 0);
    for (i = x ; i < M ; i++)
        for (j = y ; j < N ; j++)
            tab->chocolat[j][i] = 0;
}
