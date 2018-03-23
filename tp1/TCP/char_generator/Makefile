CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/char_generator
OBJ = ./obj/char_generator.o
SRC = ./src/char_generator.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
