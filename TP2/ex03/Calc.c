#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*Renvoie le resultat de la division de 'a' par 'b'*/
int division(int a, int b) {
    assert(b != 0);
    return a / b;
}

int main(int argc, char *argv[]) {
    int nb1;
    int nb2;

    if (argc != 4) {
        printf("Le nombre d'arguments n'est pas valide\n");
        exit(EXIT_FAILURE);
    }
    nb1 = atoi(argv[1]);
    if (!nb1) {
        printf("Le premier argument doit etre un entier!\n");
        exit(EXIT_FAILURE);
    }
    nb2 = atoi(argv[3]);
    if (!nb2){
        printf("Le troisieme argument doit etre un entier different de nul!\n");        
        exit(EXIT_FAILURE);
    }
    switch (argv[2][0]) {
        case '-' : printf("%d\n", nb1 - nb2); break;
        case '+' : printf("%d\n", nb1 + nb2); break;
        case 'x' : printf("%d\n", nb1 * nb2); break;
        case '/' : printf("%d\n", division(nb1, nb2)); break;
        default : printf("Deuxieme argument non valide!\n"); exit(EXIT_FAILURE);
    }
    return (0);
}
