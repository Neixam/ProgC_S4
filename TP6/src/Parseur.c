/* Auteur       : Bourennane Amine, Berthereau Thomas
 *  Creation     : 24-03-2020
 *  Modification : 24-03-2020   */
#include "Parseur.h"
#include "ListeMot.h"
#include "Affichage.h"
#include "Traitement.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Option init_option(void) {
    Option renvoie;

    renvoie.option = 0;
    renvoie.n = 1;
    renvoie.mot = NULL;
    renvoie.nom_fichier = NULL;
    return (renvoie);
}

void libere_option(Option *opt) {
    if (opt->mot) {
        free(opt->mot);
        opt->mot = NULL;
    }
    if (opt->nom_fichier) {
        free(opt->nom_fichier);
        opt->nom_fichier = NULL;
    }
}

int traite_option(int opt, char arg) {
    switch (arg) {
        case 'a' : opt = opt | 1; break;
        case 'n' : opt = opt | 2; break;
        case 's' : opt = opt | 4;
                   opt = (opt & 8) ? opt - 8 : opt; 
                   break;
        case 'p' : opt = opt | 8;
                   opt = (opt & 4) ? opt - 4 : opt;
                   break;
        case 'e' : opt = opt | 16; break;
    }
    return (opt);
}

int lecture_argument(int ac, char **av, Option *option) {
    int i;
    int drapeau;
    int verif;

    drapeau = 0;
    verif = 1;
    if (!strcmp("-test", av[1])) {
        option->option = option->option | 32;
        return (1);
    }    
    if (!(option->nom_fichier = mon_strdup(av[1])))
        return (affiche_erreur(3));
    for (i = 2 ; i < ac ; i++) {
        if (av[i][0] != '-' || (!strchr("anpse", av[i][1])
        && !(verif = strcmp("-test", &av[i][0])))) {
            if (!verif) {
                option->option = option->option | 32;
                return (1);
            }
            libere_option(option);
            return (affiche_erreur(4));
        }
        option->option = traite_option(option->option, av[i][1]);
        if ((option->option & 4 || option->option & 8)
                && option->mot == NULL) {
            i++;
            if (i >= ac) {
                libere_option(option);
                return (affiche_erreur(4));
            }
            if (est_valide(av[i])) {
                if (!(option->mot = mon_strdup(av[i]))) {
                    libere_option(option);
                    return (affiche_erreur(3));
                }
            }
            else {
                libere_option(option);
                return (affiche_erreur(5));   
            }
        }
        if (option->option & 16 && !drapeau) {
            drapeau = 1;
            i++;
            if (i >= ac) {
                libere_option(option);
                return (affiche_erreur(4));
            }
            if (option->n = atoi(av[i]) <= 0) {
                libere_option(option);
                return (affiche_erreur(4));
            }
        }
    }
    return (1);
}

int parseur_argument(int ac, char **av, FILE **fichier, Option *option) {
    if (ac < 2)
        return (affiche_erreur(1));
    if (!(lecture_argument(ac, av, option)))
        return (0);
    if (option->option & 32)
        return (1);
    if (!(*fichier = fopen(option->nom_fichier, "r"))) {
        libere_option(option);
        return (affiche_erreur(2));
    }
    return (1);
}
