/* Auteur       : Bourennane Amine, Berthereau Thomas
 *  Creation     : 24-03-2020
 *  Modification : 24-03-2020   */
#include "Affichage.h"
#include <stdio.h>
#include <string.h>

int affiche_erreur(int type_err) {
    switch (type_err) {
        case 1 : fprintf(stderr, "Manque d'un fichier\n"); break;
        case 2 : fprintf(stderr, "Fichier non accessible\n"); break;
        case 3 : fprintf(stderr, "Erreur allocation\n"); break;
        case 4 : fprintf(stderr, "Mauvaise option\noption possible :[-a -n] [-s -p] MOT [-e] N\n");
        default : fprintf(stderr, "Le mot des options -s et/ou -p est invalide\n");
    }
    return (0);	
}

void aff_mots_occ(ListeMots lst) {
    int espace;
    int i;

    for (; lst != NULL; lst = lst->suivant) {
        espace = 20 - strlen(lst->mot);
        printf("%s", lst->mot);
        for (i = 0; i <= espace; i++)
            printf(" ");
        printf("%d\n", lst->occurence);
    }
}
