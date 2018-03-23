CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/sum_it
OBJ = ./obj/sum_it.o
SRC = ./src/sum_it.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
