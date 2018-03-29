CC = gcc
CFLAGS = -Wall -std=c99 -pthread
OUTFILE = bin/pthreads
OBJ = ./obj/pthreads.o
SRC = ./src/pthreads.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
