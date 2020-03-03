/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#include "Joueur.h"

/* Renvoie la valeur du joueur adverse du joueur 'joueur' */
Joueur adversaire(Joueur joueur) {
    Joueur nemesis;

    if (joueur == JOUEUR_1)
        nemesis = JOUEUR_2;
    else
        nemesis = JOUEUR_1;
    return (nemesis);
}
