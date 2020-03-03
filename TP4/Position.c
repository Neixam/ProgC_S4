/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 25-02-2020   */
#include "Position.h"

/* Verifie si la position 'pos' est en fin de partie et si oui affecte la valeur
*  du joueur gagnant a l'adresse 'joueur_gagnant' */
int est_jeu_termine(Position pos, Joueur *joueur_gagnant) {
    assert(joueur_gagnant != NULL);
    if (pos.tab.chocolat[0][0] == 0) {
        *joueur_gagnant = pos.joueur;
        return (1);
    }
    return (0);
}
