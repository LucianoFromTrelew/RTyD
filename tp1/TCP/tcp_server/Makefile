CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/tcp_server
OBJ = ./obj/tcp_server.o
SRC = ./src/tcp_server.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
