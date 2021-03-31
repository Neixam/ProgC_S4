/* Auteur       : Bourennane Amine, Berthereau Thomas
 *  Creation     : 24-03-2020
 *  Modification : 24-03-2020   */
#include "Traitement.h"
#include "Affichage.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int est_affichable(int c) {
    if (c >= '!' && c < 127)
        return (1);
    return (0);
}

int est_alphabet(int c) {
    if (c <= 'Z' && c >= 'A')
        return (2);
    if (c <= 'z' && c >= 'a')
        return (1);
    return (0);
}

void libere_donnees(ListeMots *lst, FILE *fichier, Option *opt) {
    libere_option(opt);
    libere_lst(lst);
    if (fichier != NULL)
        fclose(fichier);
}

int lit_mot(char *tampon, int taille, FILE *flux) {
    int i;
    int c;

    tampon[0] = '\0';
    for (c = getc(flux) ; c != EOF; c = getc(flux)) {
        if (est_affichable(c)) {
            for (i = 0 ; est_affichable(c); c = getc(flux)) {
                tampon[i] = c;
                i++;
                if (i == taille - 1)
                    break;
            }
            tampon[i] = '\0';
            if (c == ' ' || c == '\n' || c == '\t')
                return (2);
            if (i == taille - 1)
                return (1);
        }
    }
    if (!*tampon)
        return (0);
    return (1);
}

char *chaine_alloue_concat(char *s1, char *s2, int liberateur) {
    char *renvoie;
    int i;
    int j;
    int taille;

    taille = strlen(s1) + strlen(s2);
    if (!(renvoie = (char*)malloc(sizeof(char) * (taille + 1))))
        return (NULL);
    for (i = 0 ; s1[i] ; i++)
        renvoie[i] = s1[i];
    for (j = 0 ; i + j < taille ; j++)
        renvoie[i + j] = s2[j];
    renvoie[i + j] = '\0';
    if (liberateur % 2 == 1)
        free(s1);
    if (liberateur > 1)
        free(s2);
    return (renvoie);
}

int est_valide(char *s) {
    int i;
    int verif;

    for (i = 0 ; s[i] ; i++) {
        if (!(verif = est_alphabet(s[i])))
            return (0);
        if (verif == 2)
            s[i] = (s[i] - 'A') + 'a';
    }
    return (1);
}

char *retire_mot_ant(char *source) {
    int i;
    int j;
    int taille;
    char *renvoie;

    for (i = 0 ; source[i] && est_alphabet(source[i]); i++);
    i++;
    taille = strlen(source) - i;
    if (!(renvoie = (char*)malloc(sizeof(char) * (taille + 1))))
        return (NULL);
    for (j = 0 ; j < taille ; j++)
        renvoie[j] = source[i + j];
    renvoie[j] = '\0';
    free(source);
    return (renvoie);
}

int traitement(FILE *fichier, ListeMots *donnee, Option opt) {
    char tampon[TAMPON_TAILLE];
    char *tmp_sauvegarde;
    int verif;
    int nb_mot;
    long pos;
    long pos_p;
    int drapeau_s;
    int drapeau_e;

    assert(fichier != NULL);
    assert(donnee != NULL);
    nb_mot = 0;
    drapeau_s = 0;
    drapeau_e = 0;
    if (!(tmp_sauvegarde = mon_strdup("")))
        return (affiche_erreur(3));
    while ((verif = lit_mot(tampon, TAMPON_TAILLE, fichier))) {
        if (verif == 2) {
            if (est_valide(tampon)) {
                if (opt.option & 4) {
                    if (!strcmp(opt.mot, tampon)) {
                        if (!drapeau_s)
                            drapeau_s = 1;
                        else {
                            nb_mot = 0;
                            free(tmp_sauvegarde);
                            if (!(tmp_sauvegarde = mon_strdup("")))
                                return (affiche_erreur(3));
                        }                            
                        continue;
                    }
                }
                if ((opt.option & 4 && drapeau_s) || !(opt.option & 4)) {
                    if (!drapeau_e) {
                        drapeau_e = 1;
                        pos = ftell(fichier);
                    }
                    if (!(tmp_sauvegarde = chaine_alloue_concat(tmp_sauvegarde, tampon, 1)))
                        return (affiche_erreur(3));
                    if (!(tmp_sauvegarde = chaine_alloue_concat(tmp_sauvegarde, " ", 1)))
                        return (affiche_erreur(3));
                    nb_mot++;
                    if (nb_mot == opt.n) {
                        if (opt.option & 8) {
                            pos_p = ftell(fichier);
                            lit_mot(tampon, TAMPON_TAILLE, fichier);
                            if (est_valide(tampon)) {
                                if (strcmp(opt.mot, tampon) != 0) {
                                    if (!(tmp_sauvegarde = retire_mot_ant(tmp_sauvegarde)))
                                        return (affiche_erreur(3));
                                    nb_mot--;
                                    fseek(fichier, pos_p, SEEK_SET);
                                    continue;
                                }
                            }
                            else {
                                free(tmp_sauvegarde);
                                if (!(tmp_sauvegarde = mon_strdup("")))
                                    return (affiche_erreur(3));
                                continue;
                            }
                        }
                        if (!ajoute_mot(tmp_sauvegarde, opt.option, donnee))
                            return (affiche_erreur(3));
                        nb_mot = 0;
                        drapeau_s = 0;
                        drapeau_e = 0;
                        if (opt.option & 16)
                            fseek(fichier, pos, SEEK_SET);
                        free(tmp_sauvegarde);
                        if (!(tmp_sauvegarde = mon_strdup("")))
                            return (affiche_erreur(3));
                    }
                }
            }
        }
        else {
            free(tmp_sauvegarde);
            if (!(tmp_sauvegarde = mon_strdup("")))
                return (affiche_erreur(3));
            nb_mot = 0;
        }
    }
    free(tmp_sauvegarde);
    if (opt.option & 2)
        tri_lst_dec(donnee);
    return (1);
}
