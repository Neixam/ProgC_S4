#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#define DELAI 500000

int intervalle_ms(struct timeval debut, struct timeval fin) {
    return ((fin.tv_sec - debut.tv_sec) * 1000
            + (fin.tv_usec - debut.tv_usec) / 1000);
}

int nb_ms_vers_centiemes(int nb_ms) {
    return (nb_ms / 10) % 100;
}

int nb_ms_vers_secondes(int nb_ms) {
    return (nb_ms / 1000) % 60;
}

int nb_ms_vers_minutes(int nb_ms) {
    return (nb_ms / 60000) % 60;
}

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
        printf("%d => %d : %d : %d : %d\n", intervalle, heure, minute, seconde, c_seconde);
    }
    return (0);
}        
        
