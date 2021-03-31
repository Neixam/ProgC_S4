#include "Parseur.h"
#include "Affichage.h"
#include "Ecriture.h"
#include "Traitement.h"
#include <stdio.h>
#include <stdlib.h>
#include "Test.h"

int main(int ac, char **av) {
    FILE *fichier;
    char *nom_ecrit;
    Option option;
    ListeMots donnee;

    fichier = NULL;
    donnee = NULL;
    option = init_option();
    if (!parseur_argument(ac, av, &fichier, &option)) {
        libere_donnees(&donnee, fichier, &option);
        exit(EXIT_FAILURE);
    }
    if (option.option & 32) {
        if (!test())
            return (1);
        printf("Tous les tests sont correctes !\n");
        return (0);
    }
    if (!traitement(fichier, &donnee, option)) {
        libere_donnees(&donnee, fichier, &option);
        exit(EXIT_FAILURE);
    }
    if (option.option & 16) {
        if (!(nom_ecrit = chaine_alloue_concat(option.nom_fichier, ".clm", 0)))
            exit(EXIT_FAILURE);
        if (!creer_fichier(donnee, nom_ecrit))
            exit(EXIT_FAILURE);
        free(nom_ecrit);
    }
    aff_mots_occ(donnee);
    libere_donnees(&donnee, fichier, &option);
    return (0);
}
