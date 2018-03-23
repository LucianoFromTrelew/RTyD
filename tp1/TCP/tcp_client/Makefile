CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/tcp_client
OBJ = ./obj/tcp_client.o
SRC = ./src/tcp_client.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
