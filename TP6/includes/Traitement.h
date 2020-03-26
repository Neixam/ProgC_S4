/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 24-03-2020
*  Modification : 24-03-2020   */
#ifndef __TRAITEMENT__
#define __TRAITEMENT__
#include <stdio.h>
#include "ListeMot.h"
#include "Parseur.h"
#define TAMPON_TAILLE 1024



/* Renvoie 1 si la lecture du fichier 'fichier' et si les allocations dans
* 'donnee' se sont bien deroulees selon les informations dans 'opt' ou sinon
* renvoie 0 */
int traitement(FILE *fichier, ListeMots *donnee, Option opt);
/* Libere toutes les informations allouer durant le deroulement du
*  programme contenue dans 'donnee', 'fichier' et 'opt'  */
void libere_donnees(ListeMots *donnee, FILE *fichier, Option *opt);
/* Renvoie une nouvelle chaine fraiche contenant la concatenation 
*  des chaines 's1' et 's2' et libere 's1' si 'liberateur' = 1
*  ou libere 's2' si 'liberateur' = 2 ou libere 's1' et 's2' si
*  'liberateur' = 3 ou si 'liberateur' = 0 ne libere aucune chaine
*   si l'allocation echoue renvoie NULL */
char *chaine_alloue_concat(char *s1, char *s2, int liberateur);
/* Renvoie 1 si la chaine 's' ne contient que des caracteres
*  alphabetique et sinon renvoie 0, change la casse en minuscule */
int est_valide(char *s);

#endif
