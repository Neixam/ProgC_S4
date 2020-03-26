/* Auteur       : Bourennane Amine, Berthereau Thomas
*  Creation     : 24-03-2020
*  Modification : 24-03-2020   */
#ifndef __LISTEMOT__
#define __LISTEMOT__

typedef struct lst {
    char *mot;
    int occurence;
    struct lst *suivant;
} CelluleMot, *ListeMots;

/* Renvoie un ListeMots contenant 'mot'
*  avec une occurence de 1 ou NULL si 
*  l'allocation a echouee */
ListeMots alloue_mot(char *mot);
/* Renvoie une nouvelle chaine fraichement allouer ayant le contenue de 'source' 
*  ou renvoie NULL si l'allocation échoue    */
char *mon_strdup(const char *source);
/* Renvoie 1 si l'ajout du 'mot' dans 'lst' s'est bien deroulee et selon
*  le type de rangement determine par 'opt' sinon renvoie 0 */
int ajoute_mot(char *mot, int opt, ListeMots *lst);
/* Libere les elements de 'lst' */
void libere_lst(ListeMots *lst);
/* Trie la liste 'lst' par ordre decroissant du champs occurence */
void tri_lst_dec(ListeMots *lst);

#endif
