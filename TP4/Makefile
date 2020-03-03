NAME		=	tp4

SRC			=	Coup.c			\
            	Graphique.c		\
				Joueur.c		\
				Tablette.c		\
				Position.c		\
				Chomp.c			\

MAIN		=	Main.c			\

OBJ			=	$(SRC:.c=.o)	\
				$(MAIN:.c=.o)	\

FLAGS		=	-Wall			\
				-ansi			\
				-pedantic		\
				-O2				\

HEADER		=	$(foreach src, $(SRC), $(src := $(shell grep $(src:.c=.?) -e "include \"" | cut -d\" -f 2)))

all			:	$(NAME) $(HEADER)

$(NAME)		:	$(OBJ) 
	gcc $(FLAGS) $^ -o $@ -lncurses

#$(OBJ)		:	$(HEADER[$@]) $($*+.c)
#	gcc -c $*.c $(FLAGS)

Main.o		:	Chomp.h Main.c
	gcc -c $*.c $(FLAGS)
	@/bin/echo $(HEADER[Main.c])

Coup.o		:	Coup.h Tablette.h Position.h Coup.c
	gcc -c $*.c $(FLAGS)

Tablette.o	:	Tablette.h Tablette.c
	gcc -c $*.c $(FLAGS)

Graphique.o :	Graphique.h Position.h Coup.h Graphique.c
	gcc -c $*.c $(FLAGS)

Joueur.o 	:	Joueur.h Joueur.c
	gcc -c $*.c $(FLAGS)

Position.o	:	Position.h Joueur.h Tablette.h Position.c
	gcc -c $*.c $(FLAGS)

Chomp.o 	:	Chomp.h Position.h Graphique.h Joueur.h Coup.h Chomp.c
	gcc -c $*.c $(FLAGS)

delo		:
	/bin/rm -rf $(OBJ)

delexe		:
	/bin/rm -rf $(NAME)

delall		:	delo delexe

re			:	delall all
