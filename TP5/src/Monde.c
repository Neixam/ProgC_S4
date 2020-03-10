/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 03-03-2020
*  Modification : 03-03-2020   */
#include "Monde.h"
#include "Graphique.h"
#include "Case.h"
#include <stdlib.h>

int intervalle_ms(struct timeval debut, struct timeval fin) {
    return ((fin.tv_sec - debut.tv_sec) * 1000
            + (fin.tv_usec - debut.tv_usec) / 1000);
}

int case_libre(Monde mon, Case pos) {
    EnsembleP tampon;
    Serpent tampon_s;

	if (pos.coord_x >= mon.nb_colonne || pos.coord_x < 0)
		return (0);
	if (pos.coord_y >= mon.nb_ligne || pos.coord_y < 0)
		return (0);
    for (tampon = mon.pomme_presente ; tampon ; tampon = tampon->suivant)
        if (compare_case(pos, tampon->pomme.pos))
            return (0);
    for (tampon_s = mon.serpent ; tampon_s ; tampon_s = tampon_s->corps) {
        if (compare_case(pos, tampon_s->coord))
            return (0);
    }
	return (1);
}

int ajoute_pomme_monde(Monde *mon) {
    Pomme nouvelle;
    EnsembleP tampon;

    nouvelle = pomme_effet_gen_alea(mon->nb_ligne, mon->nb_colonne);
    if (!case_libre(*mon, nouvelle.pos))
        return (0);
    if (!(tampon = (EnsembleP)malloc(sizeof(Pommes))))
        exit(EXIT_FAILURE);
    tampon->pomme.pos.coord_x = nouvelle.pos.coord_x;
    tampon->pomme.pos.coord_y = nouvelle.pos.coord_y;
    tampon->pomme.effet = nouvelle.effet;
    tampon->suivant = mon->pomme_presente;
    mon->pomme_presente = tampon;
    return (1);
}

Serpent init_serpent(Monde mon) {
    Serpent retour;
    Serpent tampon;
    int i;

    tampon = NULL;
    for (i = 0 ; i < mon.taille_serpent ; i++) {
        if (!(retour = (Serpent)malloc(sizeof(Morceau))))
            exit(EXIT_FAILURE);
        retour->coord.coord_x = mon.nb_colonne / 2 + i - mon.taille_serpent - 1;
        retour->coord.coord_y = mon.nb_ligne / 2;
        retour->sens = EST;
        retour->corps = tampon;
        tampon = retour;
    }
    return (retour);
}


int deplacer_serpent(Monde *mon) {
    Serpent tampon_s;
    Case nouvelle;
    Case tampon_c;

    nouvelle = prochaine_case(mon->serpent);
    if (!case_libre(*mon, nouvelle))
        return (0);
    for (tampon_s = mon->serpent ; mon->serpent ;
         mon->serpent = mon->serpent->corps) {
        tampon_c = mon->serpent->coord;
        mon->serpent->coord = nouvelle;
        nouvelle = tampon_c;
    }
    mon->serpent = tampon_s;
    return (1);
}

int manger_pomme_serpent(Monde *mon) {
    Case nouvelle;
    EnsembleP tampon;
    EnsembleP mangee;

    nouvelle = prochaine_case(mon->serpent);
    if (compare_case(nouvelle, mon->pomme_presente->pomme.pos)) {
        switch (mon->pomme_presente->pomme.effet) {
            case POISON : return (-1);
            case ANXIOGENE : mon->boost_tour++;
                           gettimeofday(&(mon->debut_boost), NULL); break;
            case DOREE : mon->nb_pomme_mangee++;
                        if (!ajout_morceau(&(mon->serpent), nouvelle)) {
                            exit(EXIT_FAILURE);
                        } nouvelle = prochaine_case(mon->serpent);
            case NORMAL : mon->nb_pomme_mangee++;
                        if (!ajout_morceau(&(mon->serpent), nouvelle)) {
                            exit(EXIT_FAILURE); 
                        } break;
        }
        mangee = mon->pomme_presente;
        mon->pomme_presente = mangee->suivant;
        free(mangee);
        return (1);
    }
    for (tampon = mon->pomme_presente ; mon->pomme_presente 
         && mon->pomme_presente->suivant ;
         mon->pomme_presente = mon->pomme_presente->suivant) {
        if (compare_case(nouvelle, mon->pomme_presente->suivant->pomme.pos)) {
            switch (mon->pomme_presente->suivant->pomme.effet) {
                case POISON : return (-1);
                case ANXIOGENE : mon->boost_tour++;
                                gettimeofday(&(mon->debut_boost), NULL); break;
                case DOREE : mon->nb_pomme_mangee++;
                            if (!ajout_morceau(&(mon->serpent), nouvelle)) {
                                exit(EXIT_FAILURE);
                            } nouvelle = prochaine_case(mon->serpent);
                case NORMAL : mon->nb_pomme_mangee++;
                            if (!ajout_morceau(&(mon->serpent), nouvelle)) {
                                exit(EXIT_FAILURE);
                            }; break;
            }
            mangee = mon->pomme_presente->suivant;
            mon->pomme_presente->suivant = mangee->suivant;
            free(mangee);
            mon->pomme_presente = tampon;
            return (1);
        }
    }
    return (0);
}

int mort_serpent(Monde mon) {
    Serpent tampon_s;
    Case nouvelle;

    nouvelle = prochaine_case(mon.serpent);
	if (nouvelle.coord_x >= mon.nb_colonne || nouvelle.coord_x < 0)
		return (1);
	if (nouvelle.coord_y >= mon.nb_ligne || nouvelle.coord_y < 0)
		return (1);
    for (tampon_s = mon.serpent->corps ; tampon_s ; tampon_s = tampon_s->corps) {
        if (compare_case(nouvelle, prochaine_case(tampon_s)))
            return (1);
    }
	return (0);
}
