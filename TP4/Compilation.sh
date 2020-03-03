# Auteur        : Bourennane Amine, Berthereau Thomas
#  Creation     : 25-02-2020
#  Modification : 25-02-2020   
gcc -Wall -ansi -pedantic -c Tablette.c
gcc -Wall -ansi -pedantic -c Joueur.c
gcc -Wall -ansi -pedantic -c Graphique.c
gcc -Wall -ansi -pedantic -c Position.c
gcc -Wall -ansi -pedantic -c Chomp.c
gcc -Wall -ansi -pedantic -c Coup.c
gcc -Wall -ansi -pedantic -c Main.c
gcc -Wall -ansi -pedantic Main.o Tablette.o Joueur.o Graphique.o Coup.o Chomp.o Position.o -o chomp -lncurses
