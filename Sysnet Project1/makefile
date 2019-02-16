cflags = -g -Wall
CC = gcc

objects = myshell.o parse.o commands.o

myshell : $(objects)
	$(CC) -o myshell $(objects)

myshell.o : myshell.c parse.h commands.h

commands.o : commands.c parse.h commands.h

parse.o : parse.c parse.h commands.h

.PHONY : clean
clean:
	rm test $(objects)
