/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#ifndef __JOUEUR__
#define __JOUEUR__

/*Représente 2 joueurs d'un jeu*/
typedef enum{
    JOUEUR_1,
    JOUEUR_2
} Joueur;

/* Renvoie la valeur du joueur adverse du joueur 'joueur' */
Joueur adversaire(Joueur joueur);

#endif
