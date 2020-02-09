/* Auteur       : Thomas Berthereau, Amine Bourenanne
*  Creation     : 04-02-2020
*  Modification : 09-02-2020                           */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*Renvoie le resultat de 'a' modulo 'b' pour 'b' positif*/
int bon_modulo(int a, int b) {
    int res;
    assert(b > 0);
    
    res = a % b;
    if (res < 0)
        return res + b;
    return res;
}

int main(int argc, char * argv[]) {
    int clee;
    int i;
    int tmp;
    int longueur;

    if (argc != 3)
        exit(EXIT_FAILURE);
    if ((clee = atoi(argv[1]))) {
        clee = bon_modulo(clee, 26);
        longueur = strlen(argv[2]);
        for (i = 0; i < longueur ; i++) {
            if (argv[2][i] >= 'A' && argv[2][i] <= 'Z') {
                if ((tmp = (argv[2][i] - clee)) < 'A')
                    tmp += 26;
                argv[2][i] = tmp;
            }
            if (argv[2][i] >= 'a' && argv[2][i] <= 'z') {
                if ((tmp = (argv[2][i] - clee)) < 'a')
                    tmp += 26;
                argv[2][i] = tmp;
            }
        }
    }
    printf("%s\n", argv[2]);
    return 0;
} 
