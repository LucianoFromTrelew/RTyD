CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/using_functions
OBJ = ./obj/using_functions.o
SRC = ./src/using_functions.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
