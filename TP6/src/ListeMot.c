/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 24-03-2020
*  Modification : 24-03-2020   */
#include "ListeMot.h"
#include <stdlib.h>
#include <string.h>

char *mon_strdup(const char *source) {
    int i;
    int taille;
    char *renvoie;

	if (!source)
		return (NULL);
    taille = strlen(source);
    if (!(renvoie = (char *)malloc(sizeof(char) * (taille + 1))))
        return (NULL);
    for (i = 0 ; i < taille ; i++)
        renvoie[i] = source[i];
    renvoie[i] = '\0';
    return (renvoie);
}

void libere_lst(ListeMots *lst) {
    if (!*lst)
        return ;
    libere_lst(&(*lst)->suivant);
	free((*lst)->mot);
    free(*lst);
}

ListeMots alloue_mot(char *mot) {
    ListeMots lst;

    if (!(lst = (ListeMots)malloc(sizeof(CelluleMot))))
        return (NULL);
    if (!(lst->mot = mon_strdup(mot))) {
        free(lst);
        return (NULL);
    }
    lst->occurence = 1;
    lst->suivant = NULL;
    return lst;
}

int ajoute_mot(char *mot, int opt, ListeMots *lst) {
    ListeMots tampon1;
    ListeMots tampon2;
    int difference;

    if (!*lst) {
        if (!(*lst = alloue_mot(mot)))
            return (0);
        return (1);
    }
    if (opt & 1) {
        if ((difference = strcmp((*lst)->mot, mot)) >= 0) {
            if (difference == 0) {
                (*lst)->occurence++;
                return (1);
            }
            tampon1 = *lst;
            if (!(*lst = alloue_mot(mot))) {
                *lst = tampon1;
                return (0);
            }
            (*lst)->suivant = tampon1;
            return (1);
        }
    }
    if (!strcmp((*lst)->mot, mot)) {
        (*lst)->occurence++;
        return (1);
    }        
    for (tampon1 = *lst ; (*lst)->suivant ; *lst = (*lst)->suivant) {
        if ((difference = strcmp((*lst)->suivant->mot, mot)) >= 0) {
            if (difference == 0) {
                (*lst)->suivant->occurence++;
                *lst = tampon1;
                return (1);
            }
            if (opt & 1) {
                tampon2 = (*lst)->suivant;
                if (!((*lst)->suivant = alloue_mot(mot))) {
                    *lst = tampon1;
                    return (0);
                }
                (*lst)->suivant->suivant = tampon2;
                *lst = tampon1;
                return (1);
            }
        }
    }
    if (!strcmp((*lst)->mot, mot)) {
        (*lst)->occurence++;
        *lst = tampon1;
        return (1);
    }        
    if (!((*lst)->suivant = alloue_mot(mot))) {
        *lst = tampon1;
        return (0);
    }
    *lst = tampon1;
    return (1);
}

int max_occurence(ListeMots lst) {
    int max_occu;

	if (lst == NULL)
		return (0);
    for (max_occu = lst->occurence ; lst ; lst = lst->suivant)
		if (max_occu < lst->occurence)
			max_occu = lst->occurence;
	return (max_occu);
}

ListeMots extrait_max(ListeMots *lst) {
    ListeMots tampon;
    ListeMots renvoie;
	int	occu_max;

    if (!*lst)
        return (NULL);
    renvoie = *lst;
	if ((occu_max = max_occurence(*lst)) == renvoie->occurence) {
		*lst = (*lst)->suivant;
		renvoie->suivant = NULL;
		return (renvoie);
	}
    for (tampon = *lst; (*lst)->suivant ; *lst = (*lst)->suivant) {
		if ((*lst)->suivant->occurence == occu_max) {
			renvoie = (*lst)->suivant;
			(*lst)->suivant = (*lst)->suivant->suivant;
			renvoie->suivant = NULL;
			*lst = tampon;
			return (renvoie);
		}
    }
	renvoie = (*lst);
	(*lst) = (*lst)->suivant;
	renvoie->suivant = NULL;
	*lst = tampon;
	return (renvoie);
}

void tri_lst_dec(ListeMots *lst) {
    ListeMots tampon1;
    ListeMots tampon2;

    tampon1 = extrait_max(lst);
    for (tampon2 = tampon1 ; *lst ; tampon1 = tampon1->suivant) {
        tampon1->suivant = extrait_max(lst);
	}
	*lst = tampon2;
}
