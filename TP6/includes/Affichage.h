/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 24-03-2020
*  Modification : 24-03-2020   */
#ifndef __AFFICHAGE__
#define __AFFICHAGE__
#include "ListeMot.h"

/* Affiche dans la sortie d'erreur l'erreur du code 'type_err' 
*  et renvoie 0 */
int affiche_erreur(int type_err);
/* Affiche dans le terminal l'occurence de chaque mot de la liste */
void aff_mots_occ(ListeMots lst);

#endif
