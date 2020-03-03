/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#include "Coup.h"

/* Renvoie 1 si le coup 'coup' est valide dans la postion 'pos' et 0 sinon */
int est_legal(Position pos, Coup coup) {
    int carre_choco;
    int coord_x;
    int coord_y;

    coord_x = coup.coord_x;
    coord_y = coup.coord_y;
    if ((coord_x < 0) || (coord_y < 0) || (coord_x >= M) || (coord_y >= N))
        return 0;
    carre_choco = pos.tab.chocolat[coord_y][coord_x];
    if (carre_choco)
        return 1;
    return 0;
}

/* Joue le coup 'coup' dans la position 'pos' et passe au joueur suivant */
void jouer_coup(Position *pos, Coup coup) {
    int coord_x;
    int coord_y;

    coord_x = coup.coord_x;
    coord_y = coup.coord_y;
    manger(&(pos->tab), coord_x, coord_y);
    pos->joueur = adversaire(pos->joueur);
}
