main: main.o
 gcc main.o -o main -Wall -Werror
main.o: main.c
 gcc -c main.c

