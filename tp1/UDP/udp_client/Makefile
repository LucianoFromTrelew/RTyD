CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/udp_client
OBJ = ./obj/udp_client.o
SRC = ./src/udp_client.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
