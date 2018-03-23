CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/tick
OBJ = ./obj/tick.o
SRC = ./src/tick.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
