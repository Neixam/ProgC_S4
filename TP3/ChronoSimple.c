#include <sys/time.h>


int intervalle_ms(struct timeval debut, struct timeval fin) {
    return fin.tv_usec - debut.tv_usec;
}

int nb_ms_vers_centiemes(int nb_ms) {
    return (nb_ms / 10) % 100;
}

int nb_ms_vers_secondes(int nb_ms) {
    return (nb_ms / 60000) % 60;
}

int nb_ms_vers_minutes(int nb_ms) {
    return (nb_ms / 360000) % 60;
}

int nb_ms_vers_heures(int nb_ms) {
    return (nb_ms / (360 *  1000 * 24));
}
