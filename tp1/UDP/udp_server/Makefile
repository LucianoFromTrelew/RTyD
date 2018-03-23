CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/udp_server
OBJ = ./obj/udp_server.o
SRC = ./src/udp_server.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
