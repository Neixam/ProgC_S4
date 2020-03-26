/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 24-03-2020
*  Modification : 24-03-2020   */
#ifndef __PARSEUR__
#define __PARSEUR__
#include <stdio.h>

typedef struct {
    int option;
    int n;
    char *mot;
    char *nom_fichier;
} Option;

/* Renvoie 1 si les arguments transmi par 'av' un tableau de chaine de  
*  caractere de taille 'ac' sont corrects et range si cela est possible le 
*  fichier dans l'adresse de 'fichier' et de ranger l'option trouvee dans 
*  l'adresse 'option' ou renvoie 0 si les arguments sont incorrects */
int parseur_argument(int ac, char **av, FILE **fichier, Option *option);
/* Initialise une variable de type structure Option */
Option init_option(void);
/* Libere les allocations effectuees dans 'opt' */
void libere_option(Option *opt);

#endif
