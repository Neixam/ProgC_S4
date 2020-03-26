CC = gcc

CFLAGS = -ansi -pedantic -Wall

EXEC = clm

SRC =	Main.c \
		Parseur.c \
		Traitement.c \
		ListeMot.c \
		Affichage.c \
		Ecriture.c \
		Test.c \

HEADER = includes/

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

SRC_PATH = $(shell find src -type d)

vpath %.c $(foreach rep, $(SRC_PATH), $(rep):)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_PATH)Main.o : $(HEADER)Traitement.h $(HEADER)Test.h

$(OBJ_PATH)Parseur.o : $(HEADER)Parseur.h $(HEADER)ListeMot.h $(HEADER)Affichage.h $(HEADER)Traitement.h 

$(OBJ_PATH)Traitement.o : $(HEADER)Traitement.h $(HEADER)Affichage.h 

$(OBJ_PATH)ListeMot.o : $(HEADER)ListeMot.h

$(OBJ_PATH)Affichage.o : $(HEADER)Affichage.h

$(OBJ_PATH)Ecriture.o : $(HEADER)Affichage.h $(HEADER)Ecriture.h

$(OBJ_PATH)Test.o : $(HEADER)Parseur.h $(HEADER)ListeMot.h $(HEADER)Affichage.h $(HEADER)Traitement.h 

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
