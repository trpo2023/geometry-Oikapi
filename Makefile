all: main

main: main.c
	gcc -o main main.c -Wall -Werror
	
clean:
	rm -f main
