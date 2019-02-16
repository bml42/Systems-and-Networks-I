cflags = -g -Wall
CC = gcc

objects = matrix.o functions.o

matrix : $(objects)
	$(CC) $(cflags) matrix.c functions.c -o matrix

matrix.o : matrix.c functions.h

functions.o : functions.c functions.h

.PHONY : clean

clean :
	rm $(objects) matrix



