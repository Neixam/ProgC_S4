/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 25-02-2020
*  Modification : 02-03-2020   */
#include "Chomp.h"

/* Demande a deux utilisateurs deux valeurs strictement superieur a 1 et affecte
*  a la valeur de l'adresse 'nb_partie' la moyenne de ces deux valeurs */
void recupere_nb_partie(int *nb_partie) {
    int nb_joueur_1;
    int nb_joueur_2;
    int erreur;

    assert(nb_partie != NULL);
    mvprintw(LINES / 2, COLS / 2, "Combien de partie voulez-vous M.Joueur 1 ?");
    erreur = 0;
    do {
        refresh();
        if (erreur)
            mvprintw(LINES / 2, COLS / 2,
                    "Le nombre saisie n'est pas valide. Donnez-en un nouveau");
        mvscanw(LINES / 2 + 1, COLS / 2, "%d", &nb_joueur_1);
        erreur = 1;
        clear();
    } while (nb_joueur_1 < 1);
    mvprintw(LINES / 2, COLS / 2, "Et vous M.Joueur 2 ?");
    erreur = 0;
    do {
        refresh();
        if (erreur)
            mvprintw(LINES / 2, COLS / 2,
                    "Le nombre saisie n'est pas valide. Donnez-en un nouveau");
        mvscanw(LINES / 2 + 1, COLS / 2, "%d", &nb_joueur_2);
        erreur = 1;
        clear();
    } while (nb_joueur_2 < 1);
    *nb_partie = (nb_joueur_1 + nb_joueur_2) / 2;
}

/* Recupere le nombre de partie voulant etre faites durant le match et lance
*  celui-ci. Affiche la gagnant de la serie si il y en a un */
void match(void) {
    int nb_partie;
    int i;
    int gagner_j1;
    int gagner_j2;

    recupere_nb_partie(&nb_partie);
    noecho();
    curs_set(0);
    gagner_j1 = 0;
    gagner_j2 = 0;
    for (i = 0 ; i < nb_partie ; i++)
        (partie(i + 1, nb_partie) == JOUEUR_1) ? gagner_j1++ : gagner_j2++;
    clear();
    if (gagner_j1 != gagner_j2)
        mvprintw(LINES / 2, COLS / 2, "Le gagnant du match est joueur %d",
                (gagner_j1 > gagner_j2) ? 1 : 2);
    else
        mvprintw(LINES / 2, COLS / 2, "Match nul personne ne l'emporte");
}

/* Lance la partie numero 'num_partie' et l'affiche ainsi que le nombre de
*  partie 'nb_partie' renvoie le joueur gagnant de la partie et l'affiche */
Joueur partie(int num_partie, int nb_partie) {
    Position pos;
    Coup coup;
    Joueur gagnant;

    pos.joueur = JOUEUR_1;
    pos.tab = creer_tablette();
    while (!est_jeu_termine(pos, &gagnant)) {
        clear();
        mvprintw(LINES - 1, COLS - 25, "Partie #%2d/%2d", num_partie, nb_partie);
        afficher_position(pos);
        refresh();
        coup = lire_coup(pos);
        jouer_coup(&pos, coup);
    }
    clear();
    mvprintw(LINES / 2, COLS / 2, "Le vainqueur de la partie est joueur %d",
             (gagnant == JOUEUR_1) ? 1 : 2);
    refresh();
    getch();
    return (gagnant);
}
