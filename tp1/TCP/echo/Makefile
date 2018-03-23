CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = bin/echo
OBJ = ./obj/echo.o
SRC = ./src/echo.c


$(OUTFILE): $(OBJ)
	$(CC) -o $(OUTFILE) $(OBJ) $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)

clean:
	$(RM) ./obj/* ./bin/*
