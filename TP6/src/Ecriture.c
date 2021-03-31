/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 24-03-2020
*  Modification : 24-03-2020   */
#include "Ecriture.h"
#include "Affichage.h"
#include <stdio.h>
#include <string.h>

int creer_fichier(ListeMots lst, char *nom) {
    FILE *fichier;
    int espace;
    int i;

    if (!(fichier = fopen(nom, "w")))
        return (affiche_erreur(3));
    for (; lst != NULL; lst = lst->suivant) {
        espace = 20 - strlen(lst->mot);
        fprintf(fichier, "%s", lst->mot);
        for (i = 0; i <= espace; i++)
            fprintf(fichier, " ");
        fprintf(fichier, "%d\n", lst->occurence);
    }
    fclose(fichier);
    return 1;
}
