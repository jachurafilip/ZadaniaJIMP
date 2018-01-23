CC = gcc


all: main.o
	$(CC) main.o -o test -lgmp
	rm -f *.o


main.o: main.c rsa.c rsa.h
	$(CC) main.c -c -o main.o -lgmp

		

