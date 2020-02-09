/* Auteur       : Thomas Berthereau, Amine Bourenanne
*  Creation     : 04-02-2020
*  Modification : 09-02-2020                           */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*Renvoie le resultat de 'a' modulo 'b' pour 'b' positif*/
int bon_modulo(int a, int b) {
    int res;
    assert(b > 0);
    
    res = a % b;
    if (res < 0)
        return res + b;
    return res;
}

int main(int argc, char *argv[]) {
    int res, nb1, nb2;

    if (argc != 3)
        exit(EXIT_FAILURE);
    nb1 = atoi(argv[1]);
    nb2 = atoi(argv[2]);
    res = bon_modulo(nb1, nb2);
    printf("Le resultat est: %d\n", res);
    return 0;
}
