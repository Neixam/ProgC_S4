/* Auteur       : Berthereau Thomas, Bourennane Amine
*  Creation     : 14-02-2020
*  Modification : 23-02-2020             */
#include <sys/time.h>
#include <unistd.h>
#include <assert.h>
#include <ncurses.h>
#define DELAI 1000

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
    return (nb_ms / (3600 * 1000));
}

/* Affiche le chronometre avec le temps 'duree_tot' ainsi que son interface */
void affiche_interface(int duree_tot) {
    int i;
    int heure;
    int minute;
    int seconde;
    int c_seconde;

    assert(duree_tot >= 0);
    heure = nb_ms_vers_heures(duree_tot);
    assert(heure < 100);
    minute = nb_ms_vers_minutes(duree_tot);
    seconde = nb_ms_vers_secondes(duree_tot);
    c_seconde = nb_ms_vers_centiemes(duree_tot);
    mvprintw(0, COLS / 2 - 8, "== Chronometre ==");
    mvprintw(LINES / 2, COLS / 2 - 6, "%2d : %2d : %2d : %2d", heure, minute,
             seconde, c_seconde);
    for (i = 0 ; i < COLS ; i++)
        mvaddch(LINES - 8, i, '-');
    mvprintw(LINES - 7, 0, "Espace : lancer / mettre en pause");
}

/* Affiche un chronometre qui incrémente sa duree et permet à l'utilisateur de
*  le mettre en pause ou non */
void menu_chrono(void) {
    struct timeval temps_debut;
    struct timeval temps_fin;
    int touche;
    int duree_totale;
    int etat;

    duree_totale = 0;
    etat = 0;
    while (1) {
        touche = getch();
        if (touche == ' ') {
            if (etat == 0) {
                etat = 1;
                gettimeofday(&temps_debut, NULL);
            }
            else
                etat = 0;
        }
        usleep(DELAI);
        if (etat == 1) {
            gettimeofday(&temps_fin, NULL);
            duree_totale += intervalle_ms(temps_debut, temps_fin);
            gettimeofday(&temps_debut, NULL);
        }
        affiche_interface(duree_totale);
        refresh();
    }
}

int main(void) {
    initscr();
    curs_set(0);
    nodelay(stdscr, TRUE);
    menu_chrono();
    endwin();
    return (0);
}
