/* Auteur       : Berthereau Thomas, Bourennane Amine
*  Creation     : 11-02-2020
*  Modification : 15-02-2020             */
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#define DELAI 500000

/* Renvoie la valeur entiere de l'intervalle entre 'debut' et 'fin' */
int intervalle_ms(struct timeval debut, struct timeval fin) {
    return ((fin.tv_sec - debut.tv_sec) * 1000
            + (fin.tv_usec - debut.tv_usec) / 1000);
}

/* Renvoie la valeur entiere de la conversion de 'nb_ms' en centiemes de 
*  secondes                 */
int nb_ms_vers_centiemes(int nb_ms) {
    return (nb_ms / 10) % 100;
}

/* Renvoie la valeur entiere de la conversion de 'nb_ms' en secondes */
int nb_ms_vers_secondes(int nb_ms) {
    return (nb_ms / 1000) % 60;
}

/* Renvoie la valeur entiere de la conversion de 'nb_ms' en minutes */
int nb_ms_vers_minutes(int nb_ms) {
    return (nb_ms / 60000) % 60;
}

/* Renvoie la valeur entiere de la conversion de 'nb_ms' en heures */
int nb_ms_vers_heures(int nb_ms) {
    return (nb_ms / (360 * 1000));
}

int main(void) {
    int heure;
    int minute;
    int seconde;
    int c_seconde;
    int intervalle;
    struct timeval debut;
    struct timeval fin;

    gettimeofday(&debut, NULL);
    while (1) {
        gettimeofday(&fin, NULL);
        intervalle = intervalle_ms(debut, fin);
        c_seconde = nb_ms_vers_centiemes(intervalle);
        seconde = nb_ms_vers_secondes(intervalle);
        minute = nb_ms_vers_minutes(intervalle);
        heure = nb_ms_vers_heures(intervalle);
        usleep(DELAI);
        printf("%d : %d : %d : %d\n", heure, minute, seconde, c_seconde);
    }
    return (0);
}        
