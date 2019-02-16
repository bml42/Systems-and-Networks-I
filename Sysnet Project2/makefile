cflags = -g -Wall -pthread
CC = gcc

objects = mt-collatz.c

mt-collatz : $(objects)
	$(CC) -g -Wall -pthread -o mt-collatz $(objects)

.PHONY : clean
clean:
	rm mt-collatz $(objects)
