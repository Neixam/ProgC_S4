CC = gcc

CFLAGS = -ansi -pedantic -Wall

LDFLAGS = -lncurses

EXEC = serpent

SRC =	Main.c \
		Graphique.c \
		Monde.c \
		Menu.c \
		Pomme.c \
        Case.c \
		Serpent.c \

HEADER = include/

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

SRC_PATH = $(shell find src -type d)

vpath %.c $(foreach rep, $(SRC_PATH), $(rep):)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_PATH)Main.o : $(HEADER)Monde.h $(HEADER)Pomme.h $(HEADER)Menu.h

$(OBJ_PATH)Graphique.o : $(HEADER)Graphique.h $(HEADER)Pomme.h $(HEADER)Serpent.h $(HEADER)Monde.h

$(OBJ_PATH)Monde.o : $(HEADER)Monde.h $(HEADER)Serpent.h $(HEADER)Pomme.h $(HEADER)Graphique.h $(HEADER)Menu.h

$(OBJ_PATH)Pomme.o : $(HEADER)Pomme.h $(HEADER)Case.h

$(OBJ_PATH)Serpent.o : $(HEADER)Case.h $(HEADER)Serpent.h

$(OBJ_PATH)Case.o : $(HEADER)Case.h

$(OBJ_PATH)Menu.o : $(HEADER)Monde.h $(HEADER)Menu.h

$(OBJ_PATH)%.o : %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER)

clean :
	/bin/rm -f $(OBJ)

mrproper : clean
	/bin/rm -f $(EXEC)

install : $(EXEC)
	mkdir ../bin
	mv $(EXEC) ../bin/$(EXEC)
	make mrproper

uninstall : mrproper
	rm -f ../bin/$(EXEC)
	rm -rf ../bin
