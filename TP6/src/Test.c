/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 24-03-2020
*  Modification : 24-03-2020   */
#include "Traitement.h"
#include "Affichage.h"
#include "Ecriture.h"
#include "Test.h"
#include "Parseur.h"
#include "ListeMot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_mon_strdup(void) {
    char s1[4] = "Oui";
    char s3[2] = "O";
    char s4[16] = "étoile du soir";
    char *test1;
    char *test2;
    char *test3;
    char *test4;
    char *test5;

    test1 = mon_strdup(s1);
    if (strcmp(s1, test1)) {
        printf("Erreur test #1 : %s != %s\n", test1, s1);
        free(test1);
        return (0);
    }
    free(test1);
    test2 = mon_strdup("");
    if (strcmp("", test2)) {
        printf("Erreur test #2\n");
        free(test2);
        return (0);
    }
    free(test2);
    test3 = mon_strdup(s3);
    if (strcmp(s3, test3)) {
        printf("Erreur test #3 : %s != %s\n", test3, s3);
        free(test3);
        return (0);
    }
    free(test3);
    test4 = mon_strdup(s4);
    if (strcmp(s4, test4)) {
        printf("Erreur test #4 : %s != %s\n", test4, s4);
        free(test4);
        return (0);
    }
    free(test4);
    test5 = mon_strdup(NULL);
    if (test5 != NULL) {
        printf("Erreur test #5\n");
        return (0);
    }
    return (1);
}

int test_ajoute_mot(void) {
    ListeMots lst1;
    ListeMots lst2;

    lst1 = NULL;
    lst2 = NULL;
    ajoute_mot("premier", 0, &lst1);
    ajoute_mot("second", 0, &lst1);
    ajoute_mot("troisieme", 0, &lst1);
    ajoute_mot("second", 0, &lst1);
    if (strcmp(lst1->mot, "premier") || lst1->occurence != 1
        || strcmp(lst1->suivant->mot, "second") || lst1->suivant->occurence != 2
        || strcmp(lst1->suivant->suivant->mot, "troisieme")
        || lst1->suivant->suivant->occurence != 1) {
        printf("Erreur test #6\n");
        libere_lst(&lst1);
        return (0);
    }
    libere_lst(&lst1);
    ajoute_mot("apremier", 1, &lst2);
    ajoute_mot("bsecond", 1, &lst2);
    ajoute_mot("ctroisieme", 1, &lst2);
    ajoute_mot("bsecond", 1, &lst2);
    if (strcmp(lst2->mot, "apremier") || lst2->occurence != 1
        || strcmp(lst2->suivant->mot, "bsecond") || lst2->suivant->occurence != 2
        || strcmp(lst2->suivant->suivant->mot, "ctroisieme")
        || lst2->suivant->suivant->occurence != 1) {
        printf("Erreur test #7\n");
        libere_lst(&lst2);
        return (0);
    }
    libere_lst(&lst2);
    return (1);
}

int test_tri_lst_dec(void) {
    ListeMots lst;

    lst = NULL;
    ajoute_mot("second", 0, &lst);
    ajoute_mot("premier", 0, &lst);
    ajoute_mot("premier", 0, &lst);
    ajoute_mot("second", 0, &lst);
    ajoute_mot("second", 0, &lst);
    ajoute_mot("premier", 0, &lst);
    ajoute_mot("premier", 0, &lst);
    ajoute_mot("premier", 0, &lst);
    ajoute_mot("troisieme", 0, &lst);
    tri_lst_dec(&lst);
    if (strcmp(lst->mot, "premier") || strcmp(lst->suivant->mot, "second")
        || strcmp(lst->suivant->suivant->mot, "troisieme")) {
        printf("Erreur test #8\n");
        return (0);
    }
    libere_lst(&lst);
    return (1);
}


int test(void) {
    if (!test_mon_strdup())
        return (0);
    if (!test_ajoute_mot())
        return (0);
    if (!test_tri_lst_dec())
        return (0);
    return (1);
}
