CC = gcc
CFLAGS = -Wall -g
OBJ = diff.o lcs.o

all: diff

diff: $(OBJ)
	$(CC) -o diff $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f diff $(OBJ)
